//#pragma save_binary

// _backup.c
// Command to backup a player's save data.
// Created by Kyoko, 8-6-94.

#include <uid.h>
#include <daemons.h>

#define BACKUP_DIR "/data/backup"

mixed user_backup_file(object ob)
{
	string name;

	if( !ob ) return 0;
	name = (string)ob->query("name");
	return (BACKUP_DIR+base_name(ob)+"/"+name[0..0]+"/"+name+".o");
}

string user_backup_dir(object ob)
{
	string name;

	if( !ob ) return 0;
	name = (string)ob->query("name");
	return (BACKUP_DIR+base_name(ob)+"/"+name[0..0]);
}

int cmd_backup(string user)
{
	object link, body;
	string link_file, body_file, uid, link_data, body_data;

	seteuid(getuid());
	uid = getuid(this_player());
	if( user && ( user == uid || member_group(uid,"admin") ) ) {
		if( !link = FINGER_D->restore_data(user) )
			return notify_fail("No such user!\n");
	} else {
		user = uid;
		link = (object)this_player()->query_link();
	}

	body = link->query("body_ob");
	if( !body ) {
		link->restore_body();
		body = link->query("body_ob");
	}

	link_data = read_file(user_data_file(link)+".o");
	body_data = read_file(user_data_file(body)+".o");
	if( !link_data || !body_data )
		return notify_fail("Warning! No save data! Backup skipped!\n");

	link_file = user_backup_file(link);
	body_file = user_backup_file(body);
	if( !link_file || !body_file )
		return notify_fail("Warning! File names not exist!\n");

	if( file_size(link_file) == -1 )
		mkdirs(user_backup_dir(link));
	else rm(link_file);

	if( file_size(body_file) == -1 )
		mkdirs(user_backup_dir(body));
	else rm(body_file);

	write_file(link_file, link_data);
	write_file(body_file, body_data);

	if( !user || user == uid )
		write(can_read_chinese()? "��������... Ok.\n":
			"Backup save data... Ok.\n");
	else
		write(can_read_chinese()? "���� "+user+" ������... Ok.\n":
			"Backup "+user+"'s save data... Ok.\n");
	if( wizardp(this_player()) ) {
		write(can_read_chinese()? "�������ϴ��:\n": "Save data to:\n");
		write("Link: "+set_color(link_file, "HIC")+".\n");
		write("Body: "+set_color(body_file, "HIC")+".\n");
	}
	// if the user is not on line, remove it.
	link->clean_up();
	return 1;
}

int help()
{
	if( can_read_chinese() )
		write( @C_HELP
Hָ���ʽ: backup

��������ϱ�����������ʹ�������� crash �������ϴ����ܾȵû�����
�������뱸�ݵ������ڵ�״̬, ������ save ָ�

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
