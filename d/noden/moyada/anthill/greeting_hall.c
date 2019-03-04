#include "../moyada.h"

inherit ROOM;

void create()
{
	::create();
	set_short("�д���");
	set_long( @C_LONG_DESCRIPTION
���￴����������Щ�����ǽӴ����˵ĵط�����ܻ������ǻ���ʲ�����?
Ҳ�����������ȵ�����ɡ���ֵ������Ϸ���һЩ��� (bread)������(butter)
��������ԳԵ����ӡ�������������ֻ��ֵĺ�ɫ���ϡ�
C_LONG_DESCRIPTION
	);
	set( "item_desc", ([
      "bread" : "һЩ��ʣ��������������ƺ����Գԡ�\n",
      "butter" : "�Ѿ������˵����ң������������ġ�\n",
    ]) );
	set( "exits", ([
		"south" : MOYADA"anthill/cellar1",
	]) );
	set( "objects", ([
	   "ant worker#1" : MOYADA"monster/ant_worker",
	   "ant worker#2" : MOYADA"monster/ant_worker",
	   "ant waiter" : MOYADA"monster/ant_waiter",
	]) );
	reset();
}

void reset()
{
    ::reset();
    set("ant_left",5);
}
