//#pragma save_binary
#include <mudlib.h>

inherit DAEMON;

int help() ;
int cmd_overview(string arg)
{
	object *ob;
	int i,j,memory;

	if ( !arg ) return help();
	
	ob = objects();
	if ( arg == "user" )
		ob = filter_array(ob,"filter_user",this_object());
	else if ( arg == "mob" )
		ob = filter_array(ob,"filter_mob",this_object());		
	else if ( arg == "room" )
		ob = filter_array(ob,"filter_room",this_object());
	else if ( arg == "item" )
		ob = filter_array(ob,"filter_item",this_object());
	else if ( arg == "other" )
		ob = filter_array(ob,"filter_other",this_object());
	else
		return help();

	j = sizeof(ob);
	memory = 0;
	for ( i = 0 ; i < j ; i++) 
			memory += memory_info(ob[i]) ;
	write(sprintf("%s :\t %d \t������ռ\t %d \tbyte .\n",arg,j,memory) );
	return 1;
}
int filter_user(object ob)
{
	if (ob->query("user")) return 1 ;
	return 0;
}

int filter_mob(object ob)
{
	if (ob->query("npc")) return 1 ;
	return 0;
}

int filter_room(object ob)
{
	if ( (int)ob->query("max_load") != 10000000 ) return 0 ;
	return 1;
}

int filter_item(object ob)
{
	string tmps;
	int tmpd;
	if ( living(ob) || ob->query("max_load") ) return 0;
	if ( sscanf(file_name(ob),"%s#%d",tmps,tmpd) != 2 ) return 0;
	return 1;
}
int filter_other(object ob)
{
	string tmps;
	int tmpd;
	if ( living(ob) || ob->query("max_load") ) return 0;
	if ( sscanf(file_name(ob),"%s#%d",tmps,tmpd) != 2 ) return 1;
	return 0;
}

int help()
{
write("����һ������������Ŀǰ�����Ĺ��ߣ��ܺ�ʱ�䣬ҪС��ʹ�á�\n"
"	������Ŀ : user ,mob ,room, item, other .\n");
	return 1;
}
