//#pragma save_binary

/*
 * _help.c
 * description: user help command
 * authors: wayfarer, mr.x
 * last modified: 2/14/92
 * BUGS: change special case below to use mappings
 * Pallando made a few updates 930109
 * Watcher updated the help search pattern 930415
 */

#include <uid.h>
#include <help.h>
#include <config.h>
#include <daemons.h>
#include <mudlib.h>

#define STD_HELP (chinese_mode?"/doc/help/c_help_screen":"/doc/help/help_screen")
//#define STD_HELP "/doc/help/c_help_screen"
inherit DAEMON;

int chinese_mode;

void write_banner(string group, string topic) {
//  write ("---------------------------------------------------\n");
//  write ("Help for "+topic+" ("+group+")\n");
//  write ("---------------------------------------------------\n");
}

int call_help (string path, string topic)
{
	string group, file;
	object ob;

//	chinese_mode =1;
	file = path+"/_"+topic;
	//file = path+"c_"+topic;
//	write(file +"\n");
//write("test\n");
	if( chinese_mode && file_size(path+"/c_"+topic)>=0 )
		topic = "c_" + topic;

	if ((ob = find_object(file)) || (file_size(file+".c") >= 0 ) ||
		(file_size(path + "/" + topic) >=0)) {
		switch (path) {
			case HELP_DIR :
				group = "General Help";
				write_banner(group, topic);
				this_player()->more(path + "/" + topic, 0, 1);
				return 1;
				break;
			case SKILLH_DIR :
				group = "Skill Help";
				write_banner(group, topic);
				this_player()->more(path + "/" + topic, 0, 1);
				return 1;
				break;
			case WIZH_DIR :
				group = "Developer Help";
				write_banner(group, topic);
				this_player()->more(path + "/" + topic, 0 ,1);
				return 1;
				break;
			case PROPH_DIR :
				group = "Properties Help";
				write_banner(group, topic);
				this_player()->more(path + "/" + topic, 0, 1);
				return 1;
				break;
			case CONCEPT_DIR :
				group = "Concepts Help";
				write_banner(group, topic);
				this_player()->more(path + topic, 0, 1);
				return 1;
				break;
			case LPCH_DIR :
				group = "LPC Help";
				write_banner(group, topic);
				//write(path +"help/");
				this_player()->more(path + topic, 0, 1);
				//this_player()->more(path + "help/" + topic, 0, 1);
				return 1;
				break;
			case DAEMONS_DIR :
				group = "Daemons Help";
				write_banner(group, topic);
				this_player()->more(path + topic, 0, 1);
				return 1;
				break;
			case STD_CMDS :
				group = "���������";
				break;
			case WIZ_CMDS :
				group = "Developer Command";
				break;
			case WIZX_CMDS :
				group = "Developer Extra Command";
				break;
			case WIZF_CMDS :
				group = "Developer File Command";
				break;
    	    case OBJ_CMDS :
				group = "Object Reference Command";
				break;
    	    case ADM_CMDS :
				group = "Admin Command";
				break;
			default:
				group = path;
				break;
		}
		write ("---------------------------------------------------\n");
		write ("�й� "+topic+" ������ ("+group+")\n");
		write ("---------------------------------------------------\n");

		if(!ob) {
			call_other( file, "???" );
			ob = find_object( file );
		}
 
		if (!ob) {
			write("A command with that name exists, but it has an error in it.\n");
			return 1;
		}
 
		if(function_exists("help", ob)) {
			call_other(file, "help");
			return 1;
		} else {
			write ("A command with that name exists, but it has no help.\n");
			return 1;
		}
    }
 
	return 0;
}


int cmd_help(string topic)
{
	string	*search_path;
	string	arg,name ;
	int		i;
	object	ob, act_ob;
	string	bin, bintopic ;

	act_ob = this_player();
	chinese_mode = can_read_chinese();

	if(!topic || topic == "") {
		this_player()->more(STD_HELP, 0 ,1);
		return 1;
	}

	topic = lower_case (topic);
//write(topic +"\n");
	switch(topic) {

	case "properties" :	write("[Property document files]\n\n");
				this_player()->force_me("ls " + PROPH_DIR);
				return 1;
				break;
	case "efun"	:
	case "efuns"	:	write("[Efun document files]\n\n");
				this_player()->force_me("ls " + EFUN_DIR);
				return 1;
				break;
	case "lfun"	:
	case "lfuns"	: 	write("[Lfun document files]\n\n");
				this_player()->force_me("ls " + LFUN_DIR);
				return 1; 
				break;
	case "wizhelp"	:	write("[Wizhelp document files]\n\n");
				this_player()->force_me("ls " + WIZH_DIR);
				return 1;
				break;
	case "simul_efuns" :	
	case "simul_efun"  :	write("[Simul_efun document files]\n\n");
				this_player()->force_me("ls " + SE_DIR);
				return 1;
				break;
	case "applies"	:	write("[Applies document files]\n\n");
				this_player()->force_me("ls " + APPLY_DIR);
				return 1; 
				break;
	case "lpc" 	:	write("[LPC document files]\n\n");
				this_player()->force_me("ls " + LPCH_DIR);				
				return 1;
				break;
	case "concepts"	:	write("[Concepts document files]\n\n");
				this_player()->force_me("ls " + CONCEPT_DIR);
				return 1;
				break;
	}

	if(sscanf(topic, "%s %s", bin, bintopic)==2) {
		switch (bin) {
			case "help" : {
					return call_help(HELP_DIR, bintopic) ;
				}
			case "wizhelp" : {
					return call_help (WIZH_DIR, topic) ;
				}
			case "lfun" :
			case "lfuns" : {
					return (int)MAN_D -> man( bin, bintopic) ;
				}
			case "efun" :
			case "efuns" : {
					return (int)MAN_D -> man( bin, bintopic) ;
				}
			case "simul_efuns" : {
					return (int)MAN_D -> man( bin, bintopic) ;
				}
			case "applies" : {
					return (int)MAN_D -> man( bin, bintopic) ;
				}
			case "commands" : {
					search_path = explode((string)act_ob->query("PATH"), ":");
					if (search_path) {
						for (i = 0; i<sizeof(search_path); i++)
							if (call_help(search_path[i],bintopic)) return 1;
					}
					write ("There is no command by that name.\n") ;
					return 1 ;
				}
			default : {
					write ("Couldn't find help section: "+bin+".\n") ;
					return 1 ;
				}
		}
	}
	if (call_help(HELP_DIR, topic)) return 1;
	if (call_help(SKILLH_DIR, topic)) return 1;
	if (wizardp(act_ob)) {
		if (call_help(WIZH_DIR, topic)) return 1;
		if (call_help(PROPH_DIR, topic)) return 1;
		if (call_help(LPCH_DIR, topic)) return 1;
		if (call_help(CONCEPT_DIR, topic)) return 1;
		if (call_help(DAEMONS_DIR, topic)) return 1 ;
		if (call_help(HELP_DIR, topic)) return 1;

	}
  
	search_path = act_ob->query("PATH");
	if (search_path) {
		for (i = 0; i<sizeof(search_path); i++) 
			if (call_help(search_path[i],topic)) return 1; 
	}
	if (wizardp(act_ob)) {
		if( sscanf( topic, "%s %s", arg, name ) < 2 ) arg = topic;
		if ((int)MAN_D ->man( arg, name ) == 1) return 1 ;
	}

	if ((ob = present(topic,act_ob)) ||
		(environment(act_ob) && (ob = present(topic,environment(act_ob)))))
	{
		if(function_exists("help",ob))
		{
			write ("---------------------------------------------------\n");
			write ("�����й� "+topic+" �İ���(Object Help)\n");
			write ("---------------------------------------------------\n");
			ob->help();
			return 1;
		}
	}
	write("û��������İ���Ŷ���Ƿ���������أ�\n");
	return 1;
}

int help() {
	write (@HELP
Usage: help <area> topic

The help command can give you help on a number of things in the mudlib
Typing \"help\" will get you a general overview. \"help start\" will show
you some information for new players. \"help topics\" will give you list
of things you might want to read help on.
You can specify a particular area in which to look for help commands. The
HELP
);
	if (wizardp(this_player())) {
		write (
"possible areas are: help, wizhelp, commands, efuns, lfuns, simul_efuns,\n"
"applies, concepts, and lpc.\n");
	} else {
		write (
"possible areas are: help and commands.\n") ;
	}
	return 1 ;
}
