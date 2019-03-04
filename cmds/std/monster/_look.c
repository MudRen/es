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
11-16-94 Elon@Eastern.Stories - ���Ļ�����..
02-10-95 Ruby@Eastern.Stories - �������� ..
*/
 
#include <config.h>
#include <mudlib.h>
#include <daemons.h>
 
inherit DAEMON;
 
// for compatible reason. change to long, short after all
// rooms are converted.
#define LONG_DESCRIPTION    "long"
#define SHORT_DESCRIPTION   "short"
#define ITEM_DESC	"item_desc/"
#define EXTRA_LOOK              "extra_look"
 
// prototypes...
string look_in_room (object room, int if_here);
string look_at_item (string item, object user);
string convert_c_number (int num);
 
mixed *c_number;
object viewingOb, env, it;
 
int cmd_look (string str)
{
	string tmp, tmp2;
 
	it = 0;
	viewingOb = previous_object();
//  viewingOb = this_player(); 
	env = environment (viewingOb);

//Check to see if the user is blind
	if (viewingOb->query("blind"))
    	return notify_fail("���Ѿ�Ϲ�ˣ�ʲ��Ҳ��������\n");

	// are we looking at our immediate environment?
	if (!str || !stringp (str)) {
		// do we have an environment?  If not, write the default message
		if( !env ) 
			return notify_fail("����һƬ�������죬�������κζ�����\n");
		viewingOb->quick_message(look_in_room(env,1));
		return 1;
	}
		viewingOb->quick_message(look_at_item (str, viewingOb));
	return 1;
}
 
 
int can_see(object what, object who)
{
	int invis,lv;
 
	if (!(what->query (SHORT_DESCRIPTION)))
		return 0;
//	invisible or hidding player can see before wizards
	if ( what->query("player_invisible") ) 
		if (!wizardp(who) && what!=who && !who->query_temp("detect_invi"))
			return 0;
	if ( what->query_temp("hidding") ) {
		lv = who->query_level();
		if ( (int)what->query_temp("hide_score") > lv * lv 
			&& !wizardp(who) && what!=who && !who->query_temp("detect_hide"))
		return 0;
	}
	invis = what->query("invisible");
	if(!invis)
		return 1; 
	if(invis == 1 && wizardp (who))
		return 1;
	if(invis == 2 && member_group(who->query ("name"), "admin"))
		return 1;
	return 0;
}
 
string living_description(object me,object ob)
{
	object *inv;
	int i, first;
	string a1, a2, tmp, reg, race, raceat, short, gender, genat;
 
	reg = (string)ob->query(LONG_DESCRIPTION);
	if (!reg) reg = "";
 
	race = ob->query("race");
	raceat = to_chinese(race);
	gender = (string)ob->query("gender");
	genat = (me == ob)?"��":to_chinese(subjective(gender));
 
	i = sizeof(inv = all_inventory(ob));
	while (i--) {
		if ( tmp = inv[i]->query(EXTRA_LOOK)) {
		  while(sscanf(tmp, "%s$N%s", a1, a2) > 1)
		  tmp = sprintf("%s%s%s", a1, 
		  ( me == ob ) ? genat : ob->query("c_name"), a2);
			reg += tmp;
			}
        }
 
    inv = filter_array(inv, "can_see", this_object(), me);
	if( sizeof(inv) ) {
		for(i=0, first=1; i<sizeof(inv); i++) {
			short = (string)inv[i]->query(SHORT_DESCRIPTION);
			if (short) {
				if( inv[i]->query("equipped") && 
				   ((string)inv[i]->query("type") != "shield") )
				  if( first ) {
				    first = 0;
				    reg = sprintf("%s%s%s%s",reg,genat,"���ϴ��� : ",short);
                  } else
                    reg = sprintf("%s%s%s",reg,", ",short);
			}
		}
		if( !first )
		  reg += "��\n" ;
		  
        for( i=0, first=1; i<sizeof(inv); i++ ) {
			short = (string)inv[i]->query(SHORT_DESCRIPTION);
			if( short ) {
				if( inv[i]->query("wielded") || 
				    ( inv[i]->query("equipped") && 
				     ((string)inv[i]->query("type") == "shield" )) )
				  if( first ) {
				    first = 0;
				    reg = sprintf("%s%s%s%s",reg,genat,"�������� : ",short);
				  } else
                    reg = sprintf("%s%s%s",reg,", ",short);
			}
		}
		if( !first )
          reg += "��\n";
	}
		
	if( stringp(race) && race != "" )
		reg = sprintf("%s%s��������%s��\n",reg,genat,raceat);
 
	reg = sprintf("%s%s%s\n",reg,genat,STATS_D->status_string(ob));
	if (wizardp(me) || (ob == me) || me->query_temp("peeping"))
	if( sizeof(inv) ) {
		first = 1;
		for(i=0; i<sizeof(inv); i++) {
			short = (string)inv[i]->query(SHORT_DESCRIPTION);
			if(short) {
				if( inv[i]->query("wielded") || inv[i]->query("equipped") )
				  continue;
				if( first ) {
				  reg += genat + "����Я����:\n";
					first = 0;
				}
				reg += "    " + short + ".\n";
			}
		}
	}

	return reg;
}

string item_description (string str, object user)
{
	int mine, here;
	object inob;
	mapping items, doors,door;
	string tmp, ret, dir, foo,func,env2;
     
	if (str == "me")
		str = (string)viewingOb->query ("name");
 
	if (str == "here")
		return look_in_room( env, 1 );

	env2 = (string)env->query("exits/"+str) ;

	if ( env2 ) { 
		if ( door = env->query("doors/"+str) ) {
			if ( (string)door["status"] !="open" )
				return "��ߵ����ǹ����ġ�\n" ;
			else
			return look_in_room( find_object_or_load(env2), 0);
		}
		else
		return look_in_room( find_object_or_load(env2), 0);
	} 
	if( (mine=sscanf(str, "my %s", foo))==1 ) str = foo;
	else if( (here=sscanf(str, "%s here", foo))==1 ) str = foo;
 
	// Are we looking at a door?   
	if ( (dir=environment(user)->query_door(str)) )
		if (user && environment (user))
			return (string)environment(user)->query(ITEM_DESC + 
			dir + " door");
   
	if (!it && !here)
		it = present (str, user);
	if (!it && env && !mine)
		it = present(str, env);
	if (!it && (func = env->query("item_func/"+str))) {
			call_other(env,func);
		return "" ;
	}
	if ( !it && wizardp(viewingOb) )
		it = find_player(str) ;
	if (it && !can_see (it,viewingOb))
		return "����û������������\n";
 
	if (it) {
		if (living (it))
			ret = living_description (viewingOb,it);
		else
			ret = (string)it->query (LONG_DESCRIPTION);
	} else {
		if (env) {
/* okay, this is the way to get things built into the room.
   assuming that we _can_ look at objects, check for room-defined
   dummy items.  Fix to item_desc of @@fun by Grendel.*/
// Elon@ES 11-16-94, temp fix for compatible with old/new rooms
            tmp = env->query ("c_item_desc/" + str);  //old rooms
            if (tmp) ret = tmp;
              else {
                tmp = env->query (ITEM_DESC + str);
                if (tmp) ret = tmp;
              }
            if (!ret) {
				tmp = env->query (ITEM_DESC + str);
				if (tmp) {
					(string)call_other (env, tmp);
					return "";
				}
			}
		}
		else return
            "����û������������\n";
	}
 
	if (!ret || ret == "")
		return "���뿴ʲ�᣿\n";
 
	if (it) {
		if (it != viewingOb) {
			if (living (it) && !user->query("player_invisible") &&
				!user->query_temp("peeping") )
			if ( environment(viewingOb) == environment(it) )
			tell_object( it, user->query("c_name")+
			"�������㿴����֪����ʲ����ͼ....��\n" );
//			foo = capitalize((string)it->query("name"));
//			if (!foo) foo = it->query(SHORT_DESCRIPTION) ;
//			if (!foo) foo = "ĳ��";
		} 
//		else foo = sprintf("%sself", objective((string)viewingOb->query("gender")));
//		tell_room( env, ({
//			sprintf("%s looks at %s.\n", user->query ("cap_name"), (living(it)? foo: lower_case(foo))),
//			sprintf("%s��ϸ�Ĵ�����%s��\n", user->query("c_cap_name"), (living(it)? foo: lower_case(foo))) }),
//			({ user, it }) );
	} 
//	else message ("say", sprintf ("%s looks at %s.\n", user->query ("cap_name"),
//				str), environment (user), user);
	return ret;
}
 
string look_at_item (string str, object user)
{
   
//Check to see if the user can see.
	if ((int)user->query("vision"))
			return item_description (str, user);
   
//Guess there is no light here, then.
    return "����һƬ��ڣ����ֲ�����ָ��\n";
}
 
string lit_room_description(object room);
 
string look_in_room (object room,int if_here)
{
  object *contents;
  int i;
 
//Check to see if the room can be seen.
  if( room->query("no_vision") )
  	  if( room->query("no_vision_msg") )
    	return (string)room->query("no_vision_msg");
      else 
        return "����һƬ��ڣ����ֲ�����ָ��\n";
 
//Check to see if the user can see within the room.
 
  if( viewingOb->query("vision") && if_here )
    return lit_room_description(room);
   
//Check other room you want look if there exists light source  
  if (!if_here) {
    if ( room->query("light") ) 
      return lit_room_description (room);
    contents = all_inventory (room);
    for(i=0;i<sizeof(contents);i++) {
      if ( contents[i]->query("light") || contents[i]->query("vision") )
        return lit_room_description (room);
      }
	}
//Looks like there isn't any light here.
  return (if_here?"��":"��")+"��һƬ��ڣ����ֲ�����ָ��\n";
}
 
int suppress_filt (string exit, string *suppress)
{
	if( member_array(exit, suppress) == -1 )
		return 1;
	return 0;
}
int sort_contents(object one,object two)
{
	return strcmp(one->query("name"),two->query("name"));
}
int filter_cansee(object what)
{
	return can_see(what,viewingOb);
}
 
string lit_room_description (object room)
{
	string	long, *dirs,lastname,name,temp;
	object	*contents, *live,obj;
	int		i,count,visible;
	mixed	*suppress;
	mapping	exits, doors ;
 
/*  Check the player's "brief" property and get either the long or short
description as is appropriate.  If infravision is being used, minimal
details of the surroundings are given. */
		long = room->query(SHORT_DESCRIPTION) ; 
 
//  Display file_name of the room if this_player is a wizard 

	if( wizardp(viewingOb) ) 
		long = sprintf("%s (%s)", long, file_name(room));

	if( viewingOb->query("brief") && viewingOb->query_temp("force_to_look")) 
		  long += " -\n";
	else {
		  long = sprintf("%s -\n    %s", long, room->query(LONG_DESCRIPTION));
		  if( room->query("outside") )
 			long = sprintf("%s    %s", long, WEATHER_D->query_weather_msg(1));
	}
 
/* Query a room's "door_suppress" property to see what, if any, doors
and their statuses will be displayed in the room. */
 
	suppress = room->query("door_suppress");
	if (!suppress || pointerp (suppress))
	{
		doors = room->query ("doors");
		if (doors)
		{
			dirs = keys (doors);
			if (pointerp (suppress))
				dirs = filter_array (dirs, "suppress_filt", this_object(), suppress);
			i = sizeof (doors);
			while (i--)
			{
					long = sprintf( "%s    %s�ߵ�%s(%s)��%s�ġ�\n", long, to_chinese(dirs[i]),
					doors[dirs[i]]["c_name"], doors[dirs[i]]["name"], 
					to_chinese(doors[dirs[i]]["status"]) );
			}
		}
	}
 
/* Query a room's "exit_suppress" property to see what, if any, obvious
exits will be displayed or not. */
	if( !room->query("exit_invisble") ) {    
	    suppress = room->query("exit_suppress");
		exits = room->query("exits");
		if( exits ) dirs = keys(exits);
		if( pointerp(suppress) )
			dirs = filter_array(dirs, "suppress_filt", this_object(), suppress);

		// To display bold exits by Annihilator@Eastern Stories
		if( viewingOb->getenv("vt100") )
		  for( i=0; i<sizeof(dirs); i++)
		  	dirs[i] = bold(dirs[i],viewingOb);
 
	    i = sizeof (dirs);
		switch (i) {
		case 0:
            long = sprintf("%s\t���û���κ����Եĳ��ڡ�\n",long);
			break;
		case 1:
            long = sprintf("%s\t����Ψһ�ĳ�����: %s��\n",long,dirs[0]);
			break;
		case 2:
            long = sprintf("%s\t������������� %s ���� %s��\n",long,dirs[0],dirs[1]);
			break;
		default:
				long = sprintf("%s\t������������� %s ���� %s��\n",long,implode(dirs[0..(i-2)], "��") ,dirs[i-1] );
		}
	}
 
// Process inventory of the room/object being examined
	contents = all_inventory (room) - ({ viewingOb });
	contents = filter_array(contents,"filter_cansee",this_object());
    if (!i = sizeof (contents)) return long;
	contents = sort_array(contents,"sort_contents",this_object());

	lastname = ( userp(contents[i-1]) ? 
					contents[i-1]->query("title") :
					contents[i-1]->query("short") );
	obj = contents[i-1];
    count = 0;

    while (i--) {
//	name = contents[i]->query("name");
	name = ( userp(contents[i]) ? 
					contents[i]->query("title") :
					contents[i]->query("short") );
	if ( name == lastname ) {
		count ++ ;
		continue ; 
	} else 
		lastname = name ;

	if (count > 1) {
		long = sprintf("%s  %s%s%s(%s).\n",long,convert_c_number(count),
						(obj->query("unit") ? obj->query("unit") :"��"),
				      	obj->query(SHORT_DESCRIPTION),
        			    capitalize((string)obj->query("name")));
     } else {
	    long = sprintf("%s  %s(%s).\n",long,
		      	obj->query(SHORT_DESCRIPTION),
        	    capitalize((string)obj->query("name")));
	}
	count = 1;
	obj = contents[i];
	}
		if (count > 1) {
		long = sprintf("%s  %s%s%s(%s).\n",long,convert_c_number(count),
						(obj->query("unit") ? obj->query("unit"):"��"),
				      	obj->query(SHORT_DESCRIPTION),
        			    capitalize((string)obj->query("name")));
     } else {
	    long = sprintf("%s  %s(%s).\n",long,
		      	obj->query(SHORT_DESCRIPTION),
        	    capitalize((string)obj->query("name")));
	}	
	
  return long;
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
Syntax: look
        look [object]
        look my <object>
        look <object> here
 
���û��ָ�����, ���ָ������㿴�����ڵĻ���. �����ָ��
�����, ������Խ���ϸ�Ĺ۲�������.
Help
);
  return 1;
}

