//#pragma save_binary

/*
 *	    /std/board/bboard.c
 *
 *	generic bulletin board object
 *
 *
 *	Truilkan, ????	allow read/write permissions and assignment of
 *			projects, rewritten to use a mapping.
 *	Zak, 930119	added 'followup', 'mailnote'
 *   	Shemp, 930224	added maker stuff
 *	Zak, 930225	made it range from 1..x instead of 0..x-1
 *	Shemp, 930226	made the note removed message reflect the
 *			actually note removed instead of note-1
 *	Shemp, 930228	added function to enable an admin to "lock" a
 *			note so that it doesn't get removed with the
 *			automatic removal of aged notes.
 *	Zak, 930309	changed to new output format. Optimised a bit
 *			too. Also checks before mkdir({save,attic}_dir).
 *			Store all `set'able things in temp vars, so
 *			they're not lost during the restore_object()
 *			in set_save_file
 *	Zak, 930314	enhanced locking/unlocking of notes, won't
 *			archive locked notes.
 *	Zak, 930320	only messages[] is non-static, num_messages
 *			is calculated at each restore_object()
 *	Zak, 930321	set_default_long_text() to update your
 *			bboard's default long.text.
 *	Watcher, 930322	Switched name recognition to use link to
 *			prevent impersonation with monster bodies
 *	Zak, 930413	hacked to use my new mailer.
 *	Telsin, 930526	added archive_board(), does what you think.
 *			several other mods to have the board archive
 *			at each reset.
 *	Zak, 930530	unique_name() now calls get_oid(). Put in
 *			define for IVORY - undefine if using new TMI
 *			mudlib. isghost() prints a message & returns
 *			0 if player is a ghost. Archiving occurs at
 *			each post now - not on reset.
 *	Zak, 930618	added 'read next' capabilities, as well as
 *			`date of newest note in short()'. Reformatted
 *			code
 *	Zak, 930620	implemented parse_num - given appropriate args
 *			will automagically do `current', `next', etc
 *			parsing for you. It calls isghost() as well...
 *	Zak, 930621	added `note <num', `help board', save_obj &
 *			set_cur_note in each operation, show curnote
 *			in short(). Moved help text to separate file.
 *			removed curnote from short... too much hassle.
 *	Zak, 930623	current note is now just a temp variable. It
 *			only `permanently' stores the newest note that
 *			you've read. Added `read new'. Modified short()
 *			to reflect `x new notes of'. removed `last mod'
 *			tackyness. (Thanx to Telsin for ideas...)
 *	Zak, 930625	changed _CUR & _NEW to different variables, to
 *			avoid a bug in /std/objects/prop.c.
 *			Also fixed initial setting of cur note
 *			in init().
 *	Zak, 930626	installed on TMI-2, removed kludge for prop bug.
 *			reformatted short ([x notes, y new]) now..
 *      Elon@ES 111894  中文化初步...
 */

/*
 * Please mail all bugs, suggestions, ideas to zak@tmi-2, or
 * internet mail <zak@rmit.edu.au>
 */

#include <move.h>
#include <mudlib.h>
#include <daemons.h>
#include <mailer.h>

inherit OBJECT;

	// undef for TMI 1.0 based mudlibs (with link_data())
#undef IVORY

	// various defines.
#define BBOARD_HELP	"/std/board/board.help"
#define VERSION		"bboard v3.0.2z, 930626"


	// these 2 are overridden by set_max_messages & set_carryover
#define MAX_MESG	30	// max # notes before archiving
#define MIN_MESG	10	// min # notes to leave on board

	// Zak is lazy...
#define SET_CUR(x)	this_player()->set_temp("board/"+board_set, messages[x]["id"])
#define SET_CURID(x)	this_player()->set_temp("board/"+board_set, x)
#define QUERY_CUR	(int)this_player()->query_temp("board/"+board_set)
#define SET_NEW(x)	this_player()->set("board/"+board_set, messages[x]["id"])
#define QUERY_NEW	(int)this_player()->query("board/"+board_set)

#ifdef IVORY
#  define QNAME		query("name")
#  define QCAPNAME	query("cap_name")
#else
#  define QNAME		link_data("name")
#  define QCAPNAME	link_data("cap_name")
#endif

// ([messages]) contains "title", "poster", "time", "doer", "body",
// "locked", "id".  (Don't maps make great substitutes for structures? :)
int query_max_msg() { return MAX_MESG ; }
int query_min_msg() { return MIN_MESG ; }
mapping		*messages;
int		id_ref;

nosave string	attic_dir, save_dir;
nosave mapping	title;
nosave string	file, location, maker, board_set, second_arg;
nosave int	num_messages, max_messages, min_messages, carryover;


int
query_prevent_shadow()
{
	return 1;
} // query_prevent_shadow

string
query_info(int i, string field)
{
	if (i < num_messages && i >= 0)
	return messages[i][field];
	else
	return "";
}

//
// these valid_* functions are designed to be masked by the one inheriting
//

int
valid_note_read(int i)
{
	return 1;
}

int
valid_post()
{
	return 1;
}

int
valid_assign()
{
	return 0;
}

int
valid_remove(int i)
{
	string poster;

	if ( messages[i]["locked"] != geteuid(this_player()) &&
	 !member_group(geteuid(this_player()),"admin") &&
		 (string)this_player()->QCAPNAME != messages[i]["poster"]
		 && (string)this_player()->QNAME != maker ) {
		notify_fail("You can only remove your own notes.\n");
		return 0;
	}
	return 1;
} // valid_remove

int
valid_lock()
{
	return (member_group(geteuid(this_player()), "admin"));
}

//
// end valid_* maskable code.
//

void
set_carryover(int t)
{
	if (t < 0)
		t = 0;
	carryover = t;
}

int
query_carryover() {
	if (!carryover)
		carryover = query_min_msg();
	return carryover;
}

int
query_max_messages()
{
	if (!max_messages)
		max_messages = query_max_msg();
	return max_messages;
}

void
set_max_messages(int num)
{
	if (num < 0)
		num = 0;
	max_messages = num;
}

 protected void
set_maker(string o)
{
	maker = lower_case(o);
}

string
query_maker()
{
	return maker;
}

void
debug_info()
{
	printf("board_set is %s\n", board_set);
	printf("cur note is %d\n", QUERY_CUR);
	printf("new note is %d\n", QUERY_NEW);
}

string
get_time(int t)
{
	return extract(ctime(t), 0, 9);
}

string
headers()
{
	string tmp;
	int i, c;

	if (!num_messages)
		return "";
	tmp = "";
	i = -1;
	c = QUERY_CUR;
	if (!c)
	c = -1;
	while ( ++i < num_messages ) {
		tmp += sprintf("%3d %s %-12s (%s)%s %s%s\n",
		(i + 1),
		c == messages[i]["id"] ? ">" : " ",
		messages[i]["poster"],
		get_time(messages[i]["time"]),
		(messages[i]["locked"] ? "*" : " "),
		messages[i]["title"],
		(messages[i]["doer"]
			? "  <" + messages[i]["doer"] + ">" : "" ));
	}
	return tmp;
} // headers

string query_long()
{
	string s1;
	if (query("c_long.text")) s1=query("c_long.text");
	else s1=query("long.text");

	return ( sprintf("%s上面%s留言：\n%s",
		s1,
		(num_messages == 0 ? "没有任何" : "共贴了 " + num_messages + " 张"),
		headers()
		));
} // query_long


string query_short()
{
	int i, n, c;
	string ns,s1;
	object ob;
	ob = this_player() ;
	if ( ! ob ) ob = previous_object() ;
	n = (int)ob->query("board/"+board_set);
	i = num_messages;
	c = 0;
	if (query("c_short.text")) s1=query("c_short.text");
	else s1=query("short.text");
	while (i--) {
	if (messages[i]["id"] <= n)
		break;
		c++;
	}
	if (c)
		ns = sprintf("，其中 %d 张未读", c);
	else
	ns = "";
	return (sprintf("%s [ %d 张留言%s]",
		s1, num_messages, ns));
} // query_short

void
set_save_dir(string s)
{
	save_dir = s + "/";
	if (file_size(save_dir) == -1)
		mkdir(save_dir);
}

string
query_save_dir(string s)
{
	return save_dir;
}

void
set_attic_dir(string s)
{
	attic_dir = s + "/";
	if (file_size(attic_dir) == -1)
		mkdir(attic_dir);
}

string
query_attic_dir()
{
	return attic_dir;
}

void
set_location(string l)
{
	location = l;
#ifdef IVORY
	base::move(l);
#else
	ob::move(l);
#endif
}

int
move(mixed dest)
{
	return MOVE_NOT_ALLOWED;
}

void
archive_board()
{
	int i,j,m;
	string *tmpa, temp_file;
	mapping *temp_messages;

	tmpa = explode(file,"/");
	temp_file = attic_dir + tmpa[sizeof(tmpa) - 1] + "_" + time();
	temp_messages = messages;
	m = num_messages-query_carryover();
	messages = messages[0..m-1];
	save_object(temp_file);
	for (j = i = 0; i < m; i++)
		if (temp_messages[i]["locked"])
		messages[j++] = temp_messages[i];
	messages = messages[0..j-1] + temp_messages[m..num_messages-1];
	num_messages = sizeof(messages);
	save_object(file);
} // archive_board

void
set_save_file(string s)
{
	int i;
	file = save_dir + s;
#ifndef IVORY
	seteuid(geteuid(previous_object()));
#endif
	restore_object(file);
	num_messages = sizeof(messages);
	if (num_messages>=query_max_messages())
		archive_board();
	for (i = 0; i < num_messages; i++) {
		if (!messages[i]["id"])
		messages[i]["id"] = ++id_ref;
	}
	board_set = replace_string(file, "/", "_");
} // set_save_file

mixed query_save_file() {
	return file;
}

void set_default_long_text()
{
	set("long.text", "这是一个留言板，专供人留言纪事。详细用法请看 help board。\n"
);
	set("silent_look", 1);
}

void create()
{
#ifndef IVORY
	seteuid(getuid(this_object()));
#endif
	set_max_messages(query_max_msg());
	set_carryover(query_min_msg());
	set_attic_dir("/attic/boards");
	set_name("board", "留言板");
	set("short", "@@query_short");
	set("long", "@@query_long");
	set("short.text", "留言板");
	set_default_long_text();
	set("id",({"board","bulletin board"}));
	set("silent_look", 1);
	messages = ({ });
	num_messages = 0;
	id_ref = 0;
	title = ([]);
	board_set = "board/default";	// in case you forget set_save_file()
} // create

void init()
{
	add_action("new_post","post");
	add_action("read", "read");
	add_action("remove_msg", "remove");
	add_action("edit_note","edit");
	add_action("assign","assign");
	add_action("followup_note", "followup");
	add_action("mail_note", "mailnote");
	add_action("lock_note", "mlock");
	add_action("unlock_note", "munlock");
	add_action("note", "note");
	add_action("help", "help");
//	add_action("comment", "comment");
	if (!QUERY_CUR)
		SET_CURID(QUERY_NEW);
} // init

string
unique_name()
{
	return "/tmp/bb_" + getoid(this_player());
}

int
isghost()
{
	if (this_player()->query("ghost")) {
		notify_fail("Your ghostly hands pass right through the board.\n");
		return 1;
	}
}

// command argument parsing routine below

#define PN_OPT		1	// 2nd arg is optional
#define PN_NEED		2	// 2nd arg is necessary
#define PN_CUR		4	// `current' is a valid note num
#define PN_NEXT		8	// `next' is a valid note num
#define PN_NEW		16	// `new' is a valid note num

varargs int
parse_num(string str, string usage, int arg2type, string usg2)
{
	int i, c;
	string t;
	usage = "Usage: " + usage + " <num> " + (usg2 ? usg2 : "") + "\n";
	second_arg = 0;
	if (isghost())
		return -1;
	if (!str) {
		notify_fail(usage);
		return -1;
	}
	if ((arg2type & PN_NEED) && sscanf(str,"%s %s", t, second_arg) != 2) {
		notify_fail(usage);		// compulsory 2nd arg
		return -1;
	}
	if ((arg2type & PN_OPT) && (sscanf(str, "%s %s", t, second_arg) != 2))
		t = str;
	if (!t)
		t = str;
	if (  (t == "next" && !(arg2type & PN_NEXT))
	||(t == "current" && !(arg2type & PN_CUR))
	||(t == "new" && !(arg2type & PN_NEW)) ) {
		notify_fail(usage);
		return -1;
	}
	if (t == "next" || t == "current" || t == "new") {
	if (t == "new")
		c = QUERY_NEW;
	else
		c = QUERY_CUR;
	if (!c) {
		notify_fail("You haven't read a note yet!\n");
		return -1;
	}
	if (!num_messages) {
		notify_fail("There aren't any messages on this board.\n");
		return -1;
	}
	i = num_messages;
	while (i--)
		if (messages[i]["id"] <= c)
		break;
	if (t == "current") {
		if (messages[i]["id"] != c) {
		notify_fail("Current note invalid.\n");
		return -1;
		}
	} else {	// t == `new' or `next'
		if (++i == num_messages) {
		if (t == "next")
			notify_fail("At last note.\n");
		else
			notify_fail("No new notes.\n");
		return -1;
		}
	}
	return i;
	} else {			// just a number
	if (sscanf(t, "%d", i) != 1) {
		notify_fail(usage);
		return -1;
	}
	if (i < 1 || i > num_messages) {
		notify_fail("No note with that number.\n");
		return -1;
	}
	return i-1;
	}
} // parse_num

//
// actual commands follow
//

int
help(string str)
{
	if (str != "board")
	return 0;
	this_player()->more( BBOARD_HELP );
	return 1;
}

int
assign(string str)
{
	int i;

	i = parse_num(str, "assign", PN_NEED + PN_CUR, "<name>");
	if (i == -1)
	return 0;
	if (!valid_assign())
	return 0;
	messages[i]["doer"] = capitalize(second_arg);
	SET_CUR(i);
	save_object(file);
	return 1;
} // assign

int
lock_note(string str)
{
	int i;

	i = parse_num(str, "mlock", PN_CUR);
	if (i == -1)
	return 0;
	if (!valid_lock()) {
	notify_fail("Permission denied - you may not lock that note.\n");
	return 0;
	}
	messages[i]["locked"] = geteuid(this_player());
	printf("Note %s locked.\n", str);	// XXX: could check if already locked.
	SET_CUR(i);
	save_object(file);
	return 1;
} // lock_note

int
unlock_note(string str)
{
	int i;

	i = parse_num(str, "munlock", PN_CUR);
	if (i == -1)
	return 0;
	if (!valid_lock()) {
	notify_fail("Permission denied - you may not unlock that note.\n");
	return 0;
	}
	messages[i]["locked"] = 0;		// XXX: should check if locked or not
	printf("Note %s unlocked.\n", str);
	SET_CUR(i);
	save_object(file);
	return 1;
} // unlock_note

int
comment(string str)
{
	int i;

	i = parse_num(str, "comment", PN_CUR);
	if (i == -1)
	return 0;
	printf("This function does nothing at the moment.\n");
	return 1;
} // comment

int
new_post(string str)
{
	string hed;
	if (isghost())
	return 0;
	if (!valid_post())
	return 0;
	if (!str)
	str = "< no title >";
	if(title[this_player()])
	printf("Warning! You are already marked as posting!\n");

	if (num_messages >= query_max_messages()) {
	archive_board();
//	printf("Too many messages.  You must remove some first.\n");
//	return 1;
	}
	if (strlen(str) > 50) {
	notify_fail("Title is too long.\n");
	return 0;
	}
	title[this_player()] = str;
	printf("Editing note.\n");
	hed = unique_name();
	rm(hed);
	this_player()->edit(hed, "postit", this_object());
	return 1;
} // new_post

void
abort()
{
	rm ((string)this_player()->query_edit_filename());
	map_delete(title,this_player());
}

varargs int
postit(string mtitle)
{
	string filename;
	mapping msg;

	filename = (string)this_player()->query_edit_filename();
	msg = allocate_mapping(4);
	msg["title"] = mtitle ? mtitle : title[this_player()];
	msg["poster"] = capitalize((string)this_player()->QCAPNAME);
	msg["time"] = time();
	msg["body"] = read_file(filename);
	msg["id"] = ++id_ref;
	rm(filename);
	this_player()->set_edit_filename("");
	if (!msg["body"])
	return 0;
	messages += ({ msg });
	printf("Posted.\n");
	num_messages++;
	map_delete(title,this_player());
	// XXX: don't set current as your own post...
	save_object(file);
	return 1;
} // postit

int read(string str)
{
	int i;
	string tmp;

	if (id(str)) {
		printf(query_long());
		return 1;
	}

	if (str == "version") {
		printf("BBoard version: %s\n", VERSION);
		return 1;
	}

	i = parse_num(str, "read", PN_CUR + PN_NEXT + PN_NEW);
	if (i == -1)
	return 0;
	if (this_object()->valid_note_read(i)) {
	printf( inverse("[Note %3d]")+"  %-12s (%s)  "+underscore("%s%s\n"),
		(i + 1),
		messages[i]["poster"],
		get_time(messages[i]["time"]),
		messages[i]["title"],
		(messages[i]["doer"]
			? "  <" + messages[i]["doer"] + ">" : "" ));
		if (QUERY_NEW < messages[i]["id"])
		SET_NEW(i);
	SET_CUR(i);
	this_player()->more(({""}) + explode(messages[i]["body"],"\n"));
	return 1;
	}
	return 0;
} // read

int
remove_msg(string str)
{
	string poster,tmp, *tmpmsg;
	int i,j;

	i = parse_num(str, "remove", PN_CUR);
	if (i == -1)
	return 0;
	if (!valid_remove(i))
	return 0;
	messages = messages[0..(i-1)]+messages[(i+1) .. (sizeof(messages) - 1)];
	printf("Note %d removed.\n", i+1);
	num_messages--;
	save_object(file);
	return 1;
} // remove_msg


nosave int	orig_number;

int
edit_note(string str)
{
	int i, tmp, j, m;
	string *lines, fl;

	i = parse_num(str, "edit", PN_CUR);
	if (i == -1)
	return 0;
	if (messages[i]["locked"]) {
	notify_fail("That message is locked\n");
	return 0;
	}
	if (!member_group(geteuid(this_player()), "admin") &&
	messages[i]["poster"] != capitalize((string)this_player()->QCAPNAME)) {
	notify_fail("You may only edit your own messages.\n");
	return 0;
	}
	fl = unique_name();
	rm(fl);
	write_file(fl, messages[i]["body"]);
	orig_number = i;
	printf("Editing: %s\n", messages[i]["title"]);
	this_player()->edit(fl,"edit_stop_ed",this_object());
	return 1;
} // edit_note

void
edit_stop_ed()
{
	SET_CUR(orig_number);
	messages[orig_number]["body"] =
	read_file((string)this_player()->query_edit_filename());
	printf("Note %d edited.\n", orig_number + 1);
	abort();
	save_object(file);
} // edit_stop_ed

int
followup_note(string str)
{
	string *lines;
	int i;

	if (!valid_post())
	return 0;
	i = parse_num(str, "followup", PN_CUR + PN_OPT, "[<title>]");
	if (i == -1)
	return 0;

	if (num_messages >= query_max_messages()) {
	archive_board();
//	printf("Too many messages.  You must remove some first.\n");
//	return 1;
	}
	if(title[this_player()])
	printf("Warning! You are already marked as posting!\n");
	if (!second_arg)
	second_arg = "Re: " + messages[i]["title"];
	if (strlen(second_arg) > 50) {
	notify_fail("Title is too long.\n");
	return 0;
	}
	title[this_player()] = second_arg;
	printf("Following up to note %d as '%s'\n", i +  1, second_arg);
	lines = explode(messages[i]["body"],"\n");
	second_arg = unique_name();
	rm(second_arg);
	write_file(second_arg, sprintf("On %s, %s wrote:\n> %s\n",
			get_time(messages[i]["time"]),
			messages[i]["poster"],
			implode(lines, "\n> ")));
	this_player()->edit(second_arg,"postit",this_object());
	SET_CUR(i);
	return 1;
} // followup_note

int
mail_note(string str)
{
	int i;
	string myname, msg, *r;

	i = parse_num(str, "mailnote", PN_CUR);
	if (i == -1)
	return 0;
	msg = sprintf("Title: %s\nFrom:  %s\nDate:  %s\n%s\n%s\n",
			messages[i]["title"],
			messages[i]["poster"],
			get_time(messages[i]["time"]),
			(messages[i]["doer"]
			? "Doer:  " + messages[i]["doer"] + "\n" : "" ),
			messages[i]["body"]
		);

	myname = (string)this_player()->QNAME;
#if 1		// XXX: change the following if using the old mailer
	r = (string *)MAILER_D->send_mail( ([ "from" : myname, "to" : ({ myname }),
			   "subject" : "Note '" + messages[i]["title"] + "'",
			   "time" : time(), "message" : msg ]) );
#else
	r = (string *)MAILER_D->send_mail(
		({myname}), ({}), (string) this_player()->QNAME,
		"Note: " + messages[i]["title"], time(), msg );
#endif
	if (sizeof(r) != 1)
	printf("Something went wrong with the mailing\n");
	else {
	printf("Note '%s' mailed to you.\n",  messages[i]["title"]);
	MAILER_D->flush_files();
	}
	SET_CUR(i);
	return 1;
} // mail_note

int
note(string str)
{
	int i;
	if (!str)
	str = "current";
	i = parse_num(str, "note", PN_CUR + PN_NEXT);
	if (i == -1)
	return 0;
	SET_CUR(i);
	printf("Current note set to %d.\n", i+1);
	return 1;
} // note

void
clean_up()
{
	return;
} // clean_up
