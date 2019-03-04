//#pragma save_binary
// The command which use to help wizards switch their Race .
// By Ruby@Eastern.Stories '95-1-27

#include <mudlib.h>
inherit DAEMON;

int cmd_switch_race(string arg) {
	object link,body;
	string new_race,body_data,old_file,new_file,name,new_dir;

	seteuid(getuid());
	new_race = "/std/user_ob/"+arg;
	if ( file_size(new_race+".c") == -1 )
		return notify_fail("�ܱ�Ǹ��û��������� !! \n");
	link = this_player()->query_link();
	link->save_data();

	body = link->query("body_ob");
	old_file = user_data_file(body)+".o";
	if ( new_race+".o" == old_file )
		return notify_fail("�����ھ���������尡 !!\n");
    body_data = read_file(old_file);

    name = (string)body->query("name");
    new_dir = "/data/std/user_ob/"+arg+"/"+name[0..0] ;
	new_file = new_dir+"/"+name+".o";
        if( file_size(new_file) == -1 ) {
            mkdirs(new_dir);
            }
            else rm(new_file);
    if (write_file(new_file, body_data)) {
	write("OK !! ������������л���"+to_chinese(arg)+"������ Quit ����ɸ���.\n");
    this_player()->set("race",arg);
	link->set("body",new_race);
	this_player()->force_me("quit");
	rm(old_file);
	} 
	else
	write("����д��δ�ɹ�����֪ͨ��������\n");
	return 1;
}
int help()
{
	write(@HELP
Command : switch_race
Syntax  : switch_race <new_race>

    ���ָ��������Э����ʦ�Ǳ任�Լ������壬�������Ժ� ... ˬ :P)
HELP
	);
  return 1;
}
