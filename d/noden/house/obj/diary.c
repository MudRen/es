#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "old diary", "�ƾ��ռ�" );
	add( "id", ({ "diary" }) );
   set_short( "�ƾ��ռ�" );
	set_long(
		"�Ȿ�ռǿ������м�����������ˣ�����Զ�����(read)��\n"
	);
	set( "unit", "��" );
	set( "weight", 5 );
	set( "useless" );
}

void init()
{
	add_action( "do_read", "read" );
}

int do_read(string arg)
{
	if( !arg || !id(arg) ) return 0;
	this_player()->more("/d/noden/house/diary", 0, 1);
	return 1;
}
