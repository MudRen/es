
#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short("ɽ��");
	set_long( @LONG_DESCRIPTION
    ��������һ��һЩ�Ͱ�ɽ����ɵ�������ϣ�����ĵ������
�����ܴ������Ķ̲ݸ���\����Ŀ������ɽ�𣬼������ɢ����ɽ
���ϣ��������������ޡ�(rocks)��
LONG_DESCRIPTION
	);

	set_outside( "eastland" );
       set("c_item_desc",(["rocks":@C_LONG
    ��Щ�ޡ���֪���������Ｘ�����ˣ����ϲ�������̦����������ǰ
ȥ��ϸ�������ǣ�ȴ���ֽ�����·������Ҳ�߲��������˰��죬ͻȻ��
�ݴ����ĳ����������һ����ԭ���Ǹ�����(rope)����֪��˭��������
�ݴ��
C_LONG
			,"rope" : @ROPE
    ����ϸ�����������������������̫�ɣ�������ľ�����������Ķ�
�ڵ��ϣ���֪����ʲ�����⣬����ѭ��(follow)��ȥ������
ROPE
]));

	set( "exits", ([ 
		"north" : "d/eastland/6,10.east", 
		"east" : "d/eastland/7,11.east" ]) );
	set( "original", "d/eastland/6,11" );
	set( "virtual_server", "/d/eastland/virtual/east_server" );
	set( "x_coordinate", 6 );
	set( "y_coordinate", 11 );
	reset();
}

void init()
{
	add_action("do_trace","follow");
}

int do_trace(string arg)
{
        if( !arg || arg!="rope" ) 
		return notify_fail("׷��ʲ�᣿\n");

        write("��˳����������������ǰ����ͻȻ������һ���ȿ�....\n");
        this_player()->set_explore("eastland#0");
        tell_room( this_object(), 
		  this_player()->query("c_cap_name") + "����������������ȥ��������һ����У�Ȼ���˾Ͳ�����....\n",
                this_player() );
        this_player()->move_player( "/d/eastland/tomb/maze1", "SNEAK" );
        tell_room( "/d/eastland/tomb/maze1", 
                this_player()->query("c_cap_name") + "������Ķ��ڵ���������\n",
                this_player() );
        return 1;
}
