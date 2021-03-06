//#pragma save_binary

// _backup.c
// Command to backup a player's save data.
// Created by Kyoko, 8-6-94.

#include <uid.h>
int cmd_backup(string user)
{
	int chinese_mode, block_msg;
	string name;
	
	seteuid(ROOT_UID);
	chinese_mode = can_read_chinese();
	if( user && member_group((string)this_player()->query("name"),"admin") )
		name = user;
	else {
		block_msg = (int)this_player()->query_temp("block_message");
		name = (string)this_player()->query("name");
		if( !wizardp(this_player()) )
			this_player()->set_temp("block_message", 1);
	}
	"/cmds/file/_cp"->cmd_cp("/data/std/user/"+extract(name,0,0)+"/"+name+".o "+
		"/data/user_backup/user/"+name+".o");
	"/cmds/file/_cp"->cmd_cp("/data/std/connection/"+extract(name,0,0)+"/"+name+".o "+
		"/data/user_backup/connection/"+name+".o");
	this_player()->set_temp("block_message", block_msg);
	if( !user || name != user )
		write(chinese_mode? "备份资料... Ok.\n":"Backup save data... Ok.\n");
	else
		write(chinese_mode? "备份 "+name+" 的资料... Ok.\n":"Backup "+name+"'s save data... Ok.\n");
	return 1;
}

int help()
{
	if( can_read_chinese() )
		write( @C_HELP
指令格式: backup

将你的资料备份起来，假使不幸遇到 crash 或是资料错误还能救得回来。
假如你想备份的是现在的状态, 请先下 save 指令。

C_HELP
		);
	else write ( @HELP
Usage: backup

The backup command can backup your save data. Make crash not cause
much damage with you. You have batter user "save" command first.

HELP
	);
	return 1;
}
