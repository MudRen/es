//#pragma save_binary

//	File	:  /cmds/std/_suicide.c
//	Creator	:  Watcher@TMI	(02/08/93)
//
//	This command allows a player to commit suicide and have
//	the character file deleted from the database.

#include <config.h>
#include <mudlib.h>
#include <logs.h>
#define mssg ({ "冷酷无情", "残忍邪恶", "暴力血腥", "阴狠狡诈", "尔虞我诈", })

inherit DAEMON ;

//  If you do not wish suicided files to be saved in the
//  archive directory, simply #undef ARCHIVE_DIR

int busy;

int cmd_suicide()
{
	//	Block any attempts by wizards to suicide
	if(wizardp(this_player())) {
		write(
			"巫师不能自杀，如果你不想继续当巫师，请 mail 给 God。\n");
		return 1;
	}

	// 	Prevent someone from suiciding the Guest character
	if((string)this_player()->query("name") == "guest") {
		write(
			"访客不能自杀，不然别人就不能用了。\n");
		return 1;
	}

	//	Check to see if the command's busy flag is set
	if(busy) {
		write(
			"自杀指令同时只能有一个人用，现在有其他人正在考虑当中，请稍候。\n");
		return 1;
	}

	busy = 1;				//  Set busy flag on
	write(
		"如果你自杀的话，会把你这个人物的资料档永远删除掉，你确定\n"
		"要结束这个人物吗？ [y/n] ");
	input_to("confirm_suicide");

	return 1;
}

protected int confirm_suicide(string str)
{
	if(!str || member_array(lower_case(str), ({ "yes", "y" })) == -1) {
		write(
			"很好，留得青山在，不怕没柴烧——好死不如赖活著。\n");
		busy = 0;
		return 1;
	}

	write(
		"\n为了安全起见，请输入您的密码确认: ");
	input_to("pass_check", 1);

	return 1;
}

protected int pass_check(string str)
{
	string password, name;
	object *items, *usrs;
	int i;

	busy = 0;				// Reset busy flag

	//	Get player's name for backup purposes
	name = (string)this_player()->query("name");

	//	Get the user's password from the linked connection object
	password = ((object)this_player()->query_link())->query("password");

	//	Check to see the inputed password matches the actual password
	if(password != crypt(str, password)) {
		write(
			"密码错误。\n");
		return 1;
	}

	write(
		"好吧，就如你所愿。\n"
		"一道闪电由天而降，然後你的眼前一片漆黑....。\n");

	tell_room(environment(),
		"一道闪电突然从天而降，直直的打在"+this_player()->query("c_name")+
		"的头上，\n闪光过後，地上只剩下一堆灰。",
		this_player());

	//	Save the players attributes before file transfer

	this_player()->save_data();

	//	If SUICIDE defined, write all suicides to a log file

#ifdef SUICIDE
	log_file(SUICIDE, capitalize(name) + " committed suicide from " +
		 query_ip_name(this_player()) + " [" +
		 extract(ctime(time()), 4, 15) + "]\n");
#endif

	//	Either move data files to ARCHIVE_DIR dir, or completely delete

	if(ARCHIVE_DIR) {
	rename(user_data_file(this_player()) + SAVE_EXTENSION, ARCHIVE_DIR + "user/" +
	  name + SAVE_EXTENSION);
	rename(PDATA_DIR + name[0..0] + "/" + name + SAVE_EXTENSION, ARCHIVE_DIR +
	  "connection/" + name + SAVE_EXTENSION);
    "/adm/daemons/backup"->remove_backup(this_player());
	}

	else {
	rm( user_data_file(this_player()) + SAVE_EXTENSION );
	rm( PDATA_DIR + name[0..0] + "/" + name + SAVE_EXTENSION );
	"/adm/daemons/backup"->remove_backup(this_player());
	}

	//	Remove the user object and connection from the game

    usrs = users();
    for( i=0 ; i<sizeof(usrs); i++ ) {
      if( !environment(usrs[i]) || usrs[i]==this_player() ) continue;
      tell_object( usrs[i],
        sprintf("一个叫做 %s (%s) 的傻瓜终於忍受不了这个\n%s的世界，刚刚自我了断了!\n",
          this_player()->query("c_name"), this_player()->query("name"),
          mssg[random(5)] ) );
    }
    items = all_inventory( this_player() );
    for( i=0 ; i<sizeof(items); i++ )
      if( items[i]->query("prevent_drop") )
        items[i]->remove();
	destruct( this_player()->query_link() );
	destruct( this_player() );
	return 1;
}

int help() {
	write(@HELP
使用格式: suicide

这个指令将删除你的资料，请认真考虑，小心使用！
HELP
);
	return 1;
}
