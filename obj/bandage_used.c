// bandage_used.c
// Rewritten by Yueh from bandage.c for bandages (1-2-96)
#include <mudlib.h>
#include <conditions.h>

inherit OBJECT;

void create()
{
#include <compress_obj.h>
	set_name( "bandage", "绷带" );
	set_short( "绷带 (使用中)" );
	set_long(
		"绷带是一种常见的、用来使受伤的人加快恢复速度的医药用品。\n"
	);
	set( "unit", "卷" );
	set( "weight", 5 );
	set( "in_use", 1 );
	set( "prevent_drop", 1 );
	set( "prevent_insert", 1 );
}

void init()
{
	add_action("do_remove", "remove" );
}

int do_remove(string arg)
{
	object ob;
	
	ob = environment(this_object());	
	// for fix the bug of user quit or suicide.
	if( ob && living(ob) ) {
		if( !id(arg) || !query("in_use") ) return 0;
		tell_object(ob,"你将绷带拆下来丢掉。\n");
		ob->delete_temp("bandaged");
		BANDAGED->remove_effect(ob);
	}
	remove_call_out("expire");
	remove();
	return 1;
}

void set_fuel(int time)
{
    call_out( "expire", time, this_object() );
}

void expire(object obj)
{
	object ob;
	
	ob = environment(obj);
	if( !ob || !living(ob) ) {
		remove();
		return;
	}
	tell_object(ob,"你的绷带被鲜血浸透了。\n");
	do_remove("bandage");
	return;
}
