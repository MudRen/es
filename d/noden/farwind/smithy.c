//#pragma save_binary

#include "farwind.h"

inherit ROOM;

int box_moved;

void create()
{
	::create();
	set_short( "������" );
	set_long(@C_LONG
����Զ������Ψһ��һ�������̣�������ƽʱ��ϲ���������ð����̸
��������ʱ���������������Ϊ�˶Կ����˵����ԣ���������ʹ�߶��˺ü�
ǧ�׿��ף������ò��ӽ��Ϲ����������̵�һ�����������һЩ����(boxes)
��
C_LONG
               	);
	set( "light", 1 );
	set( "exits", ([
		"west" : FARWIND"smain2"
	]) );

	set( "item_func", ([
		"boxes" : "exam_boxes"
	]) );
	box_moved = 0;

	set( "objects", ([
		"smith" : FARWIND"monster/smith"
	]) );
	reset();
}

void init()
{
	add_action( "do_move", "move" );
	add_action( "do_climb", "climb" );
}

void exam_boxes()
{
	object smith;

	if( !box_moved ) {
		write( 
			"�����������ɢɢ�ض���һ��ռȥ������������һ��������\n"
		);
		if( (smith= present("smith", this_object())) && smith->query("npc") )
			write( 
				"�������������ƣ������㲻Ҫ�Ҷ�(move)��Щ���ӡ�\n"
			);
	} else {
		write( 
			"��������м䱻�˰Ὺ��һЩ��¶��һ�����µ�����(ladder)��\n"
		);
		if( (smith= present("smith", this_object())) && smith->query("npc") )
			write( "������������: �������в������󣬺���ม�\n");
	}
}

int do_move(string arg)
{
	if( !arg || arg!= "boxes" ) return 0;
	if( box_moved ) {
		write( "��С�ĵذ���Щ���Ӱ��ԭλ����ס���Ǹ����µ����ӡ�\n");
		box_moved = 0;
		delete( "item_desc/ladder" );
	} else {
		write("��С�ĵذ���Щ���ӰῪ��������һ�����µ�����(ladder)��\n"
		);
		box_moved = 1;
		add( "item_desc", ([ "ladder":
			"������������¿�һƬ��ڣ���֪����(climb)��ȥ����ʲ��Σ�գ�\n"
		]) );
	}
	return 1;
}

int do_climb(string arg)
{
	if( !box_moved ) return 0;

	this_player()->move_player( FARWIND"cellar1", "SNEAK" );
	return 1;
}
