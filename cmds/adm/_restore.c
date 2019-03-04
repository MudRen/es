//#pragma save_binary

// _restore.c
// Command to restore a player's save data.
// Created by Kyoko, 8-6-94.

#include <uid.h>
#include <daemons.h>

int help();

#define BACKUP_DIR "/data/backup"

mixed user_backup_body(object ob)
{
	string name,body;

	if( !ob ) return 0;
	name = (string)ob->query("name");
	body = (string)ob->query("body");
	return (BACKUP_DIR+body+"/"+name[0..0]+"/"+name+".o");
}
mixed user_backup_link(object ob)
{
	string name;

	if( !ob ) return 0;
	name = (string)ob->query("name");
	return (BACKUP_DIR+"/std/connection/"+name[0..0]+"/"+name+".o");
}

int cmd_restore(string user)
{
	object link, body;
	string link_file, body_file, link_data, body_data,link_name,link_name2;

	seteuid(getuid());
	if( !user ) return help();
	if( !member_group(getuid(this_player()), "admin") )
		return notify_fail("Only Admins can restore user's data file!\n");
	if( find_player(user) )
		return notify_fail("�����Ŀǰ�����ϣ�Ҫ������ quit � !\n");
	link_name = "/data/backup/std/connection/"+user[0..0]+"/"+user+".o" ;

	if (file_size(link_name) > 0) {
		if (link_data = read_file(link_name)) {
			rm("/data/std/connection/"+user[0..0]+"/"+user+".o");	
			write_file("/data/std/connection/"+user[0..0]+"/"+user+".o", link_data);
			write("Link: "+set_color(link_name, "HIC")+".\n");			
			if( !link = FINGER_D->restore_data(user) ) 
				return notify_fail("fail load user from backup !!\n");
		}
	}	
	if( !link = FINGER_D->restore_data(user) ) {
			return notify_fail("no such user !!\n");
	}
	
	link->restore_body();
	body = link->query("body_ob");

	link_data = read_file(user_backup_link(link));
	body_data = read_file(user_backup_body(link));
/*
	if( !link_data || !body_data)
		return notify_fail("Warning! No backup data! Restore skipped!\n");
*/

	link_file = user_data_file(link)+".o";
	body_file = user_data_file(body)+".o";
	if( !link_file )
		return notify_fail("Warning! File names not exist!\n");

	// remove them first, for later it will cover restored data.
	// and user can't be on line, so just remove it.
	link->clean_up();
	body->remove();
	if( file_size(link_file) == -1 )
		assure_user_save_dir(link);
	else 
		if (link_data) rm(link_file);

	if( file_size(body_file) == -1 )
		assure_user_save_dir(body);
	else 
		if (body_data) rm(body_file);

	if (link_data)
		write_file(link_file, link_data);
	if (body_data)
		write_file(body_file, body_data);

	write("��ԭ "+user+" ������... Ok.\n");
	write("���������ϴ��:\n");
	if ( link_data )
		write("Link: "+set_color(link_file, "HIC")+".\n");
	if ( body_data )
		write("Body: "+set_color(body_file, "HIC")+".\n");
	return 1;
}

int help()
{
	if( can_read_chinese() )
		write( @C_HELP
ָ���ʽ: restore <user's name>

����ҵı������Ͽ���������

C_HELP
		);
	else write ( @HELP
Usage: restore <user's name>

The restore command can restore player's backup data to save data.

HELP
	);
	return 1;
}
