//#pragma save_binary

// backup.c
// daemon to backup a player's save data.
// Created by Kyoko, 8-6-94.
// Modify By Ruby, 1-27-95.

#include <mudlib.h>
#include <daemons.h>
#include <uid.h>

inherit DAEMON;

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
int remove_backup(object user)
{
	object link,body;
	string body_file,link_file;

    seteuid(getuid());
    link = (object)user->query_link();
    body = link->query("body_ob");
	
	body_file = user_backup_file(body);
    if( file_size(body_file) != -1 ) 
		rm(body_file);
	return 1;
}
int user_backup(object user)
{
	object link, body;
	string link_file, body_file, uid, link_data, body_data;

	seteuid(getuid());
	link = (object)user->query_link();

	body = link->query("body_ob");
	if( !body ) notify_fail("*����* �������ϲ���ȷ����֪ͨ�����ʦ��\n");

	link_data = read_file(user_data_file(link)+".o");
	body_data = read_file(user_data_file(body)+".o");
	if( !link_data || !body_data )
		return notify_fail("*����* �������ϲ���ȷ����֪ͨ�����ʦ��\n");

	link_file = user_backup_file(link);
	body_file = user_backup_file(body);
	if( !link_file || !body_file )
		return notify_fail("Warning! File names not exist!\n");

	if( file_size(link_file) == -1 )
		mkdirs(user_backup_dir(link));
	else rm(link_file);
    	write_file(link_file, link_data);

	if( file_size(body_file) == -1 )
		mkdirs(user_backup_dir(body));
	else rm(body_file);
		write_file(body_file, body_data);

		write("���ϱ��� ... ��ϡ�\n");
	return 1;
}

