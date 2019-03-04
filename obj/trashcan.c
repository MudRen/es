// A trashcan
// By Annihilator@Eastern.Stories

#include <mudlib.h>

inherit CONTAINER;

void create()
{
	::create();
	set_name( "trashcan", "����Ͱ" );
	set_short( "����Ͱ" );
	set_c_open_long( "һ�������³�������Ͱ������д������Դ���գ����һ��������\n"
		"������� toss ָ����õ���Ʒ��������Ͱ��\n" );
	set( "prevent_get", 1 );
	set( "max_load", 200000 );
}

void init()
{
	add_action( "do_toss", "toss" );
}

int do_toss(string arg)
{
	object dest;

	if( !arg || !(dest = present(arg, this_player())) )
		return notify_fail("��Ҫ��ʲ�ᶫ����������Ͱ��\n");
	if( dest->query("prevent_drop") || dest->query("secure") )
		return notify_fail("�㲻�ܶ�������������\n");
	write("�㽫" + dest->query("short") + "��������Ͱ��\n");
	tell_room( environment(), 
		this_player()->query("c_name") + "��" + dest->query("short") + "��������Ͱ��\n",
		this_player() );
	call_out( "reward", 5 );
	dest->remove();
	return 1;
}

void reward()
{
	object coin;
	tell_room( environment(), 
		"����������Ͱ�ﴫ��һ����µ�Ц����\n" );
	coin = new("/std/coins");
	coin->set_type( "silver" );
	coin->set_number(1);
	coin->move( environment() );
}
