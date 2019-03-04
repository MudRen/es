//#pragma save_binary

#include <mudlib.h>

inherit ROOM;

int cup;

void create()
{
	::create();
	set_short("������");
	set_long( @C_LONG_DESCRIPTION
������һ���ϾɵĴ����ң�ǽ�ǡ��컨�嵽������֩����������һ���
��Ļҳ���һЩ�����Ӱ˵Ķ�������ɢ�ã�Ҳ������Է���һЩ���õĶ���
������ǽ����һ������(cupboard)�����������һЩ���õĶ�����
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "item_desc", ([
		"cupboard" : "�������ʮ���Ͼɣ���������˻ҳ���Ҳ���������\n"
					"һ��(search)������ȷ��������û�ж�����\n"
	]) );

	set( "exits", ([
		"down" : "/d/adventurer/hall/adv_guild"
	]) );
	set( "objects", ([
		"knife" : "/d/noden/farwind/items/knife"
	]) );
	reset();
}

void init()
{
	add_action( "do_search", "search" );
}

void reset()
{
	::reset();
	cup = 1;
}

int do_search(string arg)
{
	object obj;

	if( !arg || arg!="cupboard" )
		return notify_fail( "���ڲֿ���������ȥ��Ū������ҳ���\n");
	if( cup ) {
		write( "����ϸ�������񣬽��ֻ�ҵ�һ����ֽ����\n");
		obj = new("/d/noden/farwind/items/cup");
		obj->move(this_object());
		cup = 0;
		return 1;
	} else {
		write( "��ѳ����������⣬�������Ҷ���ϸ����һ�飬ֻ�лҳ���ľм��\n");
		return 1;
	}
}
