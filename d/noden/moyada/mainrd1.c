//#pragma save_binary

// translation done -Elon 03-10-94
#include "moyada.h"

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
   set_short( "��Ҫ��·" );
	set_long( @LONG_DESCRIPTION
������վ��Ħ�Ǵ�ǵ���Ҫ��·��������������שʯ�����ƶ���
�������ǳ����ĵ�Բ�ι㳡�롸��ɫ֮�����������Ǳ��š�������һ
���¸ǵ�ľ�췿�ӡ�
LONG_DESCRIPTION
	);

	set_outside( "moyada" );
	set( "exits", ([ 
	    "east"  : MOYADA"shop/wanfu_shop.c",
		"south" : MOYADA"mainrd5.c", 
		"north" : MOYADA"n_gate.c",  ]) );

    create_door( "east", "west", ([
        "keyword" : ({ "wooden door", "door", }),
        "name"    : "wooden door",
        "c_name"  : "ľ��",
        "c_desc"  : "ȫ�µ�ľ��",
        "status"  : "open",
    ]) );
	reset();
}
