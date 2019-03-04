//#pragma save_binary

// translation done. 2-21-94  -Elon

#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short("Զ��������");
	set_long( @C_LONG_DESCRIPTION
������Զ�������ߵĴ��ţ�·����һ�ô���(tree)��������һ���ɫ
������(house)��������һ��С·ͨ���ӱߣ����߳��˴�����һ���ţ���
�������³�����������ˮ���⣬������һЩ�������
C_LONG_DESCRIPTION
	);

	set_outside( "farwind" );
	set( "light", 1 );
	set( "exits", ([
		"west" : "/d/noden/farwind/bridge",
		"south" : "/d/noden/farwind/path1",
		"east" : "/d/noden/farwind/wbazz"
	]) );
	set( "item_desc", ([
		"tree" :
			"һ���ִ��ִ������������·�ԣ�Ҳ���������(climb)��ȥ���ƣ�\n",
		"house" :
			"һ�俴�����൱���������ӣ���Ȼ�����Щ�ƾɣ����������ƺ���С\n"
			"�ĵر����ⶰ���ӣ����ӵ���û�йأ�����Խ�ȥ(enter)���ơ�\n",
    ]) );
    set( "objects", ([
		"wild dog" : "/d/noden/farwind/monster/dog"
	]) );
	reset();
}

void init()
{
	add_action( "climb_tree", "climb" );
	add_action( "enter_house", "enter" );
}

int climb_tree( string arg )
{
	if( !arg || arg!="tree" )
		return notify_fail( "��ʲ�᣿\n" );
        if( random( 15 ) >=this_player()->query_skill("climbing") )
		return notify_fail( "����ͼ��������������һ��С�ĵ���������\n");
	this_player()->move_player( "/d/noden/farwind/tree1", "SNEAK" );
	tell_room( this_object(), 
		this_player()->query("c_name") + "�������ϡ�\n",
		this_player() );
	return 1;
}

int enter_house( string arg )
{
	if( !arg || arg!= "house" )
		return notify_fail( "�������\n" );
	this_player()->move_player( "/d/noden/farwind/healer", "SNEAK" );
	return 1;
}
