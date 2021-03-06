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
		return notify_fail("很抱歉，没有这个种族 !! \n");
	link = this_player()->query_link();
	link->save_data();

	body = link->query("body_ob");
	old_file = user_data_file(body)+".o";
	if ( new_race+".o" == old_file )
		return notify_fail("你现在就是这个种族啊 !!\n");
    body_data = read_file(old_file);

    name = (string)body->query("name");
    new_dir = "/data/std/user_ob/"+arg+"/"+name[0..0] ;
	new_file = new_dir+"/"+name+".o";
        if( file_size(new_file) == -1 ) {
            mkdirs(new_dir);
            }
            else rm(new_file);
    if (write_file(new_file, body_data)) {
	write("OK !! 现在你的种族切换至"+to_chinese(arg)+"，现在 Quit 以完成更新.\n");
    this_player()->set("race",arg);
	link->set("body",new_race);
	this_player()->force_me("quit");
	rm(old_file);
	} 
	else
	write("档案写入未成功，请通知神来处理。\n");
	return 1;
}
int help()
{
	write(@HELP
Command : switch_race
Syntax  : switch_race <new_race>

    这个指令是用来协助巫师们变换自己的种族，以利测试和 ... 爽 :P)
HELP
	);
  return 1;
}
