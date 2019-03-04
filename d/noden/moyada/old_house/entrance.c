// translation done. -Elon 03-10-94
#include "../moyada.h"

inherit ROOM;

void create()
{
	::create();
	set_short("���");
	set_long( @C_LONG_DESCRIPTION
��վ�ڹ��Ͻ�����(house)�Ĵ���ǰ, �������ڵ����ű��紵�ø¸�����, ���ﺮ
��̹�, ������ǿ, ����������ǽ��, Խ�����ô˴��Ŀ��¡��ſ�վ����ֻʯ���
, �ƺ��ھ�������ȥ��
C_LONG_DESCRIPTION
	);

	set_outside( "moyada" );
	set( "exits", ([
		"south" : MOYADA"mainrd6",
	]) );
	set( "item_desc", ([
      "house" : "һ�����϶��ƾɵķ���, �㵨�ӹ���Ļ�, Ҳ���ܽ�ȥ(enter)����.\n"
	]) );
	set( "objects", ([
	  "gargoyle#1" : MOYADA"monster/gargoyle",
	  "gargoyle#2" : MOYADA"monster/gargoyle",
	]) );
	reset();
}

void init()
{
	add_action("do_enter", "enter");
}

int do_enter(string arg)
{
   if( this_player() ) this_player()->set_explore("noden#8");
	write( "һ��Ī���Ŀ־������������ͷ!\n" );
	return 1;
}
