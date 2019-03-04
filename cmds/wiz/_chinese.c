//#pragma save_binary

// The "chinese" command.
// toggle your message language
// By Annihilator@Eastern.Stories

// close toggle function because give up english mode
// By Ruby@Rastern.Stories at 94/11/8 

#include <mudlib.h>
#include <daemons.h>

int help();

int cmd_chinese(string arg)
{
	int chinese_mode;
	string key, chinz;

//	if( can_read_chinese() ) chinese_mode = 1;

	if( !arg || arg=="" || !wizardp(this_player()) ) return help();
//	{
//		if( chinese_mode ) {
//			write("Now you see English messages.\n");
//			this_player()->delete("chinese");
//		} else {
//			write("�������趨Ϊ��������ѶϢ��\n");
//	 		this_player()->set("chinese", 1);
//		}
//		return 1;
//	}
	if( arg == "save" && member_group(geteuid(this_player()), "admin") ) {
		CHINESE_D->make_dictionary();
		write("Ok.\n");
		return 1;
	}
	if( arg == "load" && member_group(geteuid(this_player()), "admin") ) {
		CHINESE_D->read_dictionary();
		write("Ok.\n");
		return 1;
	}
	if( sscanf(arg, "remove [%s]", key ) == 1 ) {
		CHINESE_D->remove_translate(key);
		write( "Remove "+ key + " from dictionary.\nOk.\n");
		return 1;
	}
	if( sscanf(arg, "%s==%s", key, chinz)==2 ) {
		CHINESE_D->add_translate(key, chinz);
		write( key + " == " + chinz + "\nOk.\n");
		return 1;
	}
	return help();
}

int help()
{
	write ( @HELP
Syntax: chinese

This command toggles the language of message you'll be receiving between
Chinese and English.
HELP
	);
	if( wizardp(this_player()) ) write( @WIZ_HELP
	
You can also add/remove a chinese translation by using the following format:
chinese <english>==<chinese> | chinese remove <[english]>
Notice there may be blanks in <english>, and the blanks next to "==" are
recognized, too.
WIZ_HELP
	);
	if( member_group(geteuid(this_player()), "admin") ) write( @ADMIN_HELP

Another option for admin... Format: chinese [save|load]
It will save dictionary to file /adm/etc/dictionary or
load file /adm/etc/dictionary to dictionary.
ADMIN_HELP
	);
	return 1 ;
}
