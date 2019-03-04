#include "goomay.h"

inherit ROOM;

int furnace_moved;

void create()
{
        ::create() ;
        set("light", 1) ;
        set_short( "��®" );
        set_long(
@LONG
���߽�һ�Ҵ������ӣ��������Ĵ��������һƬ����ڵĵ���������
��һ��ϸ��м����Щ���Ǵ���ʱ����Ļ𻨡����ڰ�\����\���¯����������
�����������ڹ���������������һ���޴�ĺ��ң�������������®��������
��Ľ��֣�����ϸһ������ !! ԭ���ǽ������ʣ�ԭ���������������
�µ�����ʦ�������ļҡ�
LONG
        );

        set( "exits", ([
                "south" : Goomay"row22", ]));

	set( "item_func", ([
		"furnace" : "exam_furnace"
	]) );
	furnace_moved = 0;

        set( "objects", ([
                "smith1" : Mob"smith",
                "smith2" : Mob"smith",
                "master" : Mob"master_smith",
				"guest"  : Mob"traveller",
        ]) );

	reset();
}

void init()
{
	add_action( "do_move", "move" );
	add_action( "do_climb", "climb" );
}

void exam_furnace()
{
	object smith;

	if( !furnace_moved ) {
		write("��Щ¯�������������\n");
		if( (smith= present("smith", this_object())) && smith->query("npc") )
			write("�����������ƣ������㲻Ҫ�Ҷ�����¯�ӡ�\n");
	} else {
		write("���¯�ӱ����ƿ���һЩ��¶��һ��������ĵض���\n");
		if( (smith=present("smith", this_object())) && smith->query("npc") )
			write("����������: �����Ӷ��ﳣ������һЩ���������Ҫ�Լ�С�ġ�\n");
	}
}

int do_move(string arg)
{
	if( !arg || arg!= "furnace" ) return 0;
	if( furnace_moved ) {
		write("����Ǹ�¯�Ӱ��ԭλ����ס���Ǹ��ض���\n");
		furnace_moved = 0;
		delete( "c_item_desc/hole" );
	} else {
		write("��С�ĵذ��Ǹ�¯�ӰῪ��������һ��������ĵض� !\n");
		furnace_moved = 1;
		add( "c_item_desc", ([ "hole":
			"������ض����¿�һƬ��ڣ���֪������ȥ����ʲ��Σ�գ�\n"
		]) );
	}
	return 1;
}

int do_climb(string arg)
{
        if( !furnace_moved )
        return notify_fail("���ڵ��ϵ���������\n");
        tell_room( this_object(), 
        this_player()->query("c_name") + "��������ض�...��ѽ ! ��ͷ�½��ϵ��Խ�ȥ�ˣ�����ʵ���� ...\n",
                this_player() );

	this_player()->move_player( Goomay"cellar1", "SNEAK" );
        tell_room( Goomay"cellar1", 
                this_player()->query("c_name") + "�Ӷ���ֱֱ������������\n"
                ,this_player() );

	return 1;
}
