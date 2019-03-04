
// This is the mount object, inherited by monsters can be mounted.
// By Annihilator Sep 14, 1994
// Modify By Ruby@ES 1995-6-18 

void init()
{
	add_action( "do_mount", "mount" );
	add_action( "do_dismount","dismount");
}

int do_mount(string arg)
{
	object ob;
	
//	if( ob= previous_object()->query_temp("mounting") )
	if( ob= this_player()->query_temp("mounting") )	
		return notify_fail(
			"���Ѿ�����һ" + ob->query("unit") + ob->query("c_name") + "���ˡ�\n");

	if( !this_object()->id(arg) ) return notify_fail("��Ҫ��ʲ�᣿\n");
//	if( previous_object()->query("stop_attack") ) return 0;
	if( this_player()->query("stop_attack") ) return 0;	
	return "/adm/daemons/mount"->mount(this_object(), this_player());
}

int do_dismount()
{
    return "/adm/daemons/mount"->dismount(this_object(),this_player());
}


