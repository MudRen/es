//#pragma save_binary
/* File:  /cmds/std/_look.c
   Creator:		Matt. D. Robinson (Yakker/Regret@TMI) 1991
   Updated:		Help added by Brian (1/28/92)
				Rewritten by Adam Beeman (Buddha@TMI) 6/25/92
				Light handling by Steven Schmidt (Mobydick@TMI) 11/9/92
				Contents processing routines, light handling updated,
				   and infravision by Glenn Ferguson (Watcher@TMI) 1/29/93
				Got querying item_desc to work properly if the
				   description was a function by Grendel @ TMI-2,
				   10 August 1993
				Rewritten and door/exit suppression added by Austin H.
				   Ziegler (Fantome@TMI) 11 August 1993

		This code allows a user to "look" in a room, or at a specific
object in the user's inventory or environment.
*/

#include <config.h>
#include <mudlib.h>
#include <daemons.h>

inherit DAEMON;

/* Contents display format flag:
		0 == standard look
		1 == line by line processed
		2 == processed linked together
*/
#define FLAG 1

#define LONG_DESCRIPTION	(chinese_mode ? "long" : "long")
#define SHORT_DESCRIPTION	(chinese_mode ? "short" : "short")
#define ITEM_DESCRIPTION	(chinese_mode ? "c_item_desc/" : "item_desc/")

// prototypes...
string look_in_room (object room, int flag);
varargs string look_at_item (string item, object user, string inn);
string look_in_item (string item, object user);
string convert_number (int num);
string convert_c_number (int num);
string process_contents (mixed *inv, int flag);
int content_match (object what);

mixed *number, *c_number;
object viewingOb, env, it;
int chinese_mode;

/* cmd_look (string)
 * this function 'look's in a room and handles the case of
 * whether it's just the room or a separate object.
 */
int cmd_look (string str)
{
	int oldStatus;   
	string tmp, tmp2;
	mapping exits, doors;
	mixed *hidden_exits, *hidden_doors;

	it = 0;
	viewingOb = this_player();
	env = environment (viewingOb);
	chinese_mode = can_read_chinese();

/* Check to see if we have an argument list.  If we do, see if
we're trying to look at a particular object.  If so, get the
object's description.  Otherwise, ask the room for its description.
*/
  
// are we looking at our immediate environment?
	if (!str || !stringp (str)) {
// do we have an environment?  If not, write the default message
		if (!env) {
			write (chinese_mode?"����һƬ�������죬�������κζ�����\n":"There is nothing to see here.\n");
			return 1;
		}
/*
This garbles the room description. It's useful for simulating acid
flashbacks among your players. We recommend you not do that too often. :)
write (LANGUAGE_D->garble_string(look_in_room (env, (int)viewingOb->query_temp ("force_to_look")),"orcish")+"\n") ;
*/
		write (look_in_room (env, (int)viewingOb->query_temp ("force_to_look")));
		return 1;
	}

// are we looking at something in a container?
	if (sscanf(str, "at %s in %s", tmp, tmp2) == 2) {
// we're looking inside a container
// blocking a look in a locked/opaque container doesn't work yet. -- Fantome
// hopefully will work soon
		write (sprintf ("%-=75s", look_at_item (tmp, viewingOb, tmp2)));
		return 1;
	}

// are we looking at an object?
	if (sscanf(str, "at %s", tmp)) {
		write (sprintf ("%-=75s", look_at_item (tmp, viewingOb)));
		return 1;
	}
// are we looking in an object?
	if (sscanf(str, "in %s", tmp)) {
		write (sprintf ("%-=75s", look_in_item (tmp, viewingOb)));
		return 1;
	}
// are we looking in the room?
	if (env) {
		exits = env->query ("exits");
		doors = env->query ("doors");
		hidden_exits = env->query ("exit_suppress");
		hidden_doors = env->query ("door_suppress");
		if (mapp (exits) && member_array (str, keys (exits)) != -1) {
			if (doors && doors[str]) {
				if (((!pointerp (hidden_doors) || (int)hidden_doors[0] != 1 ||
					member_array (str, hidden_doors) == -1))
					&& doors[str]["status"] != "open") {
				write (chinese_mode?"�Ǳߵ��Ź�ס�ˡ�\n":"The door is closed.\n");
				return 1;
				}
			}
			if ((!pointerp (hidden_exits) ||
				member_array (str, hidden_exits) == -1) ||
				(!intp (hidden_exits) || (int)hidden_exits[0] != 1)) {
				env = find_object_or_load (exits[str]);
				write (look_in_room (env, 0));
				return 1;
			}
		}
	}
	cmd_look (sprintf ("at %s", str));
	return 1;
}


int can_see (object who, object what)
{
	int invis;

	if (!(what->query (SHORT_DESCRIPTION)))
		return 0;
	invis = what->query ("invisible");
	if (!invis)
		return 1; 
	if (invis == 1 && wizardp (who))
		return 1;
	if (invis == 2 && member_group (who->query ("name"), "admin"))
		return 1;
	return 0;
}


int can_see2 (object what, object who)
{
	return can_see (who, what);
}


string living_description (object ob)
{
	object *inv;
	int i;
	string a1, a2, tmp, reg, race, raceat, short, gender, genat;

	reg = (string)ob->query(LONG_DESCRIPTION);
	if (!reg) reg = "";

	if( chinese_mode ) {
		race = ob->query("race");
		raceat = to_chinese(race);
		gender = (string)ob->query("gender");
		genat = (viewingOb == ob)?"��":to_chinese(subjective(gender));
	} else {
		race = (string)ob->query("race");
		raceat = article(race) + " " + race;
		gender = (string)ob->query("gender");
		genat = ((viewingOb == ob)?"You are":capitalize(subjective(gender)) + " is");
	}

	i = sizeof(inv = all_inventory(ob));
	while (i--)
		if (tmp = inv[i]->query("extra_look")) {
			while(sscanf(tmp, "%s$N%s", a1, a2) > 1)
				tmp = sprintf("%s%s%s", a1, capitalize((string)ob->query("name")), a2);
			reg += tmp;
		}

	if (stringp (race) && race != "")
		reg += chinese_mode? genat + "��������" + raceat + "��\n":
			genat + " " + raceat + ".\n";

	reg += genat + (chinese_mode? STATS_D->c_status_string(ob): STATS_D->status_string(ob)) + "\n";

	inv = filter_array (inv, "can_see2", this_object(), viewingOb);
	i = sizeof (inv);
	if (i) {
		reg += chinese_mode?
			genat + "����Я����:\n":
			capitalize(genat) + " carrying:\n";
		while (i--) {
			short = (string)inv[i]->query (SHORT_DESCRIPTION);
			if (short) {
				reg += "    " + short;
				if( inv[i]->query("wielded") )
					reg += chinese_mode? " (����)" : " (wielded)";
				if( inv[i]->query("equipped") )
					reg += chinese_mode? " (����)" : " (equipped)";
				reg += ".\n";
			}
		}
	}
	return reg;
}

varargs string item_description (string str, object user, int infra, string inn)
{
	int mine, here;
	object inob;
	mapping items, doors;
	string tmp, ret, dir, foo;
     
	if (str == "me")
		str = (string)viewingOb->query ("name");

	if (str == "here")
		return look_in_room( env, 0 );

	if( (mine=sscanf(str, "my %s", foo))==1 ) str = foo;
	else if( (here=sscanf(str, "%s here", foo))==1 ) str = foo;

	// Are we looking at a door?   
	if ( (dir=environment(user)->query_door(str)) )
		if (user && environment (user))
			return (string)environment(user)->query( (chinese_mode?"c_item_desc/"
			:"item_desc/") + dir + " door");
   
	if (inn) {
		inob = present (inn, user);
		if (!inob && env)
			inob = present (inn, env);
		if (inob) {
			it = present (str, inob);
			if ((int)inob->query_is_closed() && (int)inob->query ("opaque"))
				return chinese_mode?
				"�㲢û��͸�ӵ����칦\�ܡ�\n":
				"Just how do you propose looking in a closed container?\n";
		}
	}
	if (!it && !here)
		it = present (str, user);
	if (!it && env && !mine)
		it = present(str, env);
   
	if (it && !can_see (viewingOb, it))
		return chinese_mode?"����û������������\n":"I don't see that here.\n";

	if (infra && it && objectp(it))
		if (living (it) || it->query ("hot"))
			return "Your infravision shows a bright heat pattern.\n";
		else
			return "Your infravision shows no heat pattern.\n";

	if (it) {
		if (living (it))
			ret = living_description (it);
		else
			ret = (string)it->query (LONG_DESCRIPTION);
	} else {
		if (env) {
/* okay, this is the way to get things built into the room.
   assuming that we _can_ look at objects, check for room-defined
   dummy items.  Fix to item_desc of @@fun by Grendel.*/
			tmp = env->query (ITEM_DESCRIPTION + str);
			if (tmp) ret = tmp;
			if (!ret) {
				tmp = env->query ("item_func/" + str);
				if (tmp) {
					(string)call_other (env, tmp);
					return "";
				}
			}
		}
		else return chinese_mode?
			"����û���κζ�����\n":
			"There is nothing to see here.\n";
	}

	if (!ret || ret == "")
		return chinese_mode? "���뿴ʲ�᣿\n": "I don't see that here.\n";

	if (it) {
		if (it != viewingOb) {
			if (living (it))
				tell_object( it,
					user->query("c_name") + "�������㿴����֪����ʲ����ͼ....��\n");
			foo = it->query("name");
			if (!foo) foo = it->query(SHORT_DESCRIPTION) ;
			if (!foo) foo = "something";
		} 
	} 
//	else message ("say", sprintf ("%s looks at %s.\n", user->query ("cap_name"),
//				str), environment (user), user);
	return ret;
}

varargs string look_at_item (string str, object user, string inn)
{
//Check if the user is blind.
	if ((int)user->query ("blind"))      
		return chinese_mode?"���Ѿ�Ϲ�ˣ�ʲ��Ҳ��������\n":"You are blind and cannot see.\n";
   
//Check to see if the user can see.
	if ((int)user->query ("vision"))
		if (!undefinedp (inn))
			return item_description (str, user, 0, inn);
		else
			return item_description (str, user, 0);
   
//Check to see if user has infravision capabilities
	if ((int)user->query("infravision"))
		if (!undefinedp (inn))
			return item_description (str, user, 1, inn);
		else
			return item_description (str, user, 1);
   
//Guess there is no light here, then.
	return chinese_mode?"����һƬ��ڣ����ֲ�����ָ��\n"
	:"It is dark and you can't see a thing.\n";
}

string lit_room_description(object room, int infra, int flag);

varargs string look_in_room (object room, int flag)
{
	//Check to see if the user is blind
	if (viewingOb->query("blind"))
		return chinese_mode?"���Ѿ�Ϲ�ˣ�ʲ��Ҳ��������\n":"You are blind and cannot see.\n";

//Check to see if the room can be seen.
  if (room->query("no_vision"))
    return (string)room->query("no_vision") ;
   
//Check to see if the user can see within the room.
  if (viewingOb->query ("vision"))
    return lit_room_description (room, 0, flag);
   
//Check to see if the user has infravision
  if (viewingOb->query("infravision"))
    return lit_room_description (room, 1, flag);
   
	//Looks like there isn't any light here.
	return chinese_mode?"����һƬ��ڣ����ֲ�����ָ��\n"
	:"It is dark and you can't see a thing.\n";
}

int suppress_filt (string exit, string *suppress)
{
	if (member_array (exit, suppress) == -1)
		return 1;
	return 0;
}

string lit_room_description (object room, int infra, int flag)
{
	string	long, str, tmp, *dirs;
	object	*contents, *live;
	int		i;
	mixed	*suppress;
	mapping	exits, doors ;

/*  Check the player's "brief" property and get either the long or short
description as is appropriate.  If infravision is being used, minimal
details of the surroundings are given. */

	long = room->query(SHORT_DESCRIPTION);

/*  Display file_name of the room if this_player is a wizard with 
DISPLAY_PATH env set. by annihilator@Eastern.Stories */

	if( wizardp(this_player()) && !this_player()->getenv("NO_ROOM_PATHNAME") )
		long = sprintf("%s (%s)", long, file_name(room));

	if(!infra)
		if( flag && viewingOb->query("brief")) {
			long += " -\n";
		} else {
			long = sprintf ("%s -\n    %s", long, room->query (LONG_DESCRIPTION));
			if (room->query ("outside"))
			long = sprintf("%s    %s", long, WEATHER_D->query_weather_msg(chinese_mode));
		}

	if (!long)
		long = "";

/* Query a room's "door_suppress" property to see what, if any, doors
and their statuses will be displayed in the room. */

	suppress = room->query ("door_suppress");
	if (!suppress || pointerp (suppress))
	{
		doors = room->query ("doors");
		if (doors && !infra)
		{
			dirs = keys (doors);
			if (pointerp (suppress))
				dirs = filter_array (dirs, "suppress_filt", this_object(), suppress);
			i = sizeof (doors);
			while (i--)
			{
				if(chinese_mode)
					long = sprintf( "%s    %s�ߵ�%s(%s)��%s�ġ�\n", long, to_chinese(dirs[i]),
					doors[dirs[i]]["c_name"], doors[dirs[i]]["name"], 
					to_chinese(doors[dirs[i]]["status"]) );
				else
					long = sprintf ( "%s    The %s to the %s is %s.\n", 
					long, doors[dirs[i]]["name"], dirs[i], doors[dirs[i]]["status"]);
			}
		}
	}
 
/* Query a room's "exit_suppress" property to see what, if any, obvious
exits will be displayed or not. */

	suppress = room->query ("exit_suppress");
	if (!suppress || pointerp (suppress)) {
		exits = room->query ("exits");
		if (exits) dirs = keys (exits);
		if (pointerp (suppress))
			dirs = filter_array (dirs, "suppress_filt", this_object(), suppress);
/*
		// To change english into chinese by Annihilator
		if(chinese_mode) {
			i = sizeof (dirs);
			while (i--) dirs[i] = to_chinese(dirs[i]);
		}
*/
		// To display bold exits by Annihilator@Eastern Stories
		if( this_player()->getenv("vt100") ) {
		i = sizeof (dirs);
		while (i--) dirs[i] = bold(dirs[i]);
		}

	    i = sizeof (dirs);
		switch (i) {
		case 0:
			long += (chinese_mode?"\t���û���κ����Եĳ��ڡ�\n"
								 :"\tThere are no obvious exits.\n");
			break;
		case 1:
			long += (chinese_mode?"\t����Ψһ�ĳ�����: "+dirs[0]+"��\n"
								 :"\tThe only obvious exit is "+dirs[0]+".\n");
			break;
		case 2:
			long += (chinese_mode?"\t������������� "+dirs[0]+" ���� "+dirs[1]+"��\n"
								 :"\tThe obvious exits are "+dirs[0]+" and "+dirs[1]+".\n");
			break;
		default:
      		if(!chinese_mode)
				long += "\tObvious exits are " + implode (dirs[0..(i-2)], ", ") + " and " + dirs[i-1] + ".\n";
			else
				long += "\t������������� " + implode(dirs[0..(i-2)], "��") + " ���� " + dirs[i-1] + "��\n";
		}
	}

// Process inventory of the room/object being examined
  contents = all_inventory (room);
   
//  Check for infravision flag and living heat patterns
  if (infra) {
    i = sizeof (live = filter_array (contents, "filter_living", this_object()));
    switch (i) {
      case 0: {
		long += "Your infravision shows no other heat patterns.\n";
		break;
      }
      case 1: {
		long += "Your infravision shows only one heat pattern.\n";
		break;
      }
      default: {
		long = sprintf ("%sYour infravision shows %s heat patterns.\n",
				long, convert_number (i));
		break;
      }
    }
    return long;
  }
   
  if (!FLAG) {
    i = sizeof (contents);
    while (i--) {
      tmp = contents[i]->query(SHORT_DESCRIPTION)
      		+ (chinese_mode?" ("+contents[i]->query("name")+")":"");
      if (contents[i] != viewingOb && tmp && tmp != "")
		if (can_see(viewingOb, contents[i]))
		  long += tmp + ".\n";
    }
  } else
    long += process_contents (contents, FLAG);
   
  return long;
}

// Filter out all objects without a possible heat pattern
int filter_living (object what) {
  if (what == viewingOb || (userp (what) && !interactive (what)))
    return 0;
  return (living (what) && !what->query ("cold") || what->query ("hot"));
}

string look_in_item (string tmp, object user) {
  string tmp2;
  object *contents;
   
  it = present (tmp, user);
  if (!it && env)
    it = present (tmp, env);

   if (!it) return "I don't see that here.\n" ;
  if (living (it))
    return "You must be kidding me!  Look INSIDE a living being?\n";

  if ((int)it->query_is_closed() && (int)it->query ("opaque"))
    return "Just how do you propose looking in a closed container?\n";

  if (it) {
// in our hands or in our environment.
    contents = all_inventory (it);
    if (!contents) {
      return "You don't see anything inside.\n";
    } else {
      tmp2 = process_contents (contents, FLAG);
      if (tmp2 == "")
		return "You don't see anything inside.\n";
      return sprintf ("%s contains:\n%s\n", capitalize (tmp), tmp2);
    }
  }
// this is where we could look for things in the room's properties.
  return "Look in what?\n";
}

string process_contents (mixed *contents, int flag)
{
	object obj;
	mapping match;
	mixed *inv, *ninv;
	string unit, tmp, ret;
	int loop, i; 

	ret = "";
	inv = contents;
   
	// Remove all objects with no short desc or command initiator
	inv = filter_array (inv, "clean_objects", this_object());
   
	// Compile list of objects with matching short descriptions
	match = unique_mapping (inv, "query", SHORT_DESCRIPTION);
	ninv = keys (match);

	//Loop through object contents and place them into a display string
	loop = sizeof (ninv);  
	while (loop--) {
		// older code handled living cases separately.  taken out by Mobydick@TMI-2
		// on 10 April 1993, kept out by Fantome 24 July 1993 
 		i = sizeof (match[ninv[loop]]);
		if (i > 1) {
			obj = match[ninv[loop]][0];
			tmp = chinese_mode?
				sprintf ("%s%s%s (%s)", convert_c_number(i), (unit=obj->query("unit"))?unit:"��",
					ninv[loop], obj->query("name")):
				sprintf ("%s %s", capitalize(convert_number(i)), pluralize(ninv[loop]));
		} 
		else tmp = chinese_mode? ninv[loop]+" ("+match[ninv[loop]][0]->query("name")+")":
					capitalize(ninv[loop]);

		if (flag == 1)
			ret = sprintf("%s  %s.\n", ret, tmp);
		else
			ret = sprintf("%s%s%s", ret, tmp,
				((loop > 1) ? ", " : ((!loop) ? "." : ", and ")));
	}

	if (flag == 2 && ret != "")
		ret = wrap (sprintf ("You see %s", ret));
   
	return ret;
}

// Remove all invisible objects from the room's content's list
int clean_objects (object what) {
  if (!can_see (viewingOb, what))
    return 0;
  return (((string)what->query (SHORT_DESCRIPTION) && what != viewingOb) ? 1 : 0);
}

// Compare each object's short desc with processing short desc
string content_match (object what) {
  return (string)what->query(SHORT_DESCRIPTION);
}

// Convert numeric value to word format if below 21
string convert_number(int num) {
  if (!number)
    number = ({
"one", "two", "three", "four", "five", "six", "seven", "eight",
"nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
"fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
"twenty" });
   
  return ((num > 20) ? "many" : number[num - 1]);
}

// Convert numeric value to word format if below 21
string convert_c_number(int num) {
  if (!c_number)
    c_number = ({
"һ", "��", "��", "��", "��", "��", "��", "��", "��", "ʮ", "ʮһ", "ʮ��",
"ʮ��", "ʮ��", "ʮ��", "ʮ��", "ʮ��", "ʮ��", "ʮ��", "��ʮ" });
   
  return ((num > 20) ? "��\��" : c_number[num - 1]);
}

int help() {
  write (@Help
Command: look
Syntax: look [at object]
        look at my <object>
        look at <object> here

If no object is specified this command makes you look
around the room.  If an object is specified it lets you
examine the object more closely.
Help
);
  return 1;
}
