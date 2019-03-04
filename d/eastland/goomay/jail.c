#include "goomay.h"

inherit DOORS;
inherit ROOM;

void create()
{
        ::create() ;
        set_short( "����" );
        set_long(
@LONG
�����ǲ����ǹط��˵ĵط������˰��ķ��˶��������һ���򵥵�
�������Զ����η��������߹�ʱ������ķ��˶���һ��������۹⿴����
�����������\�ݵ�����ץ�㡣���������ģ������ֲ������Ͽ��ȥ��
LONG
        );
        
        set( "exits", ([ 
		"east" : Goomay"jail",
                "west" : Goomay"police",
		"north" : Goomay"jail_room1",
		"south" : Goomay"jail_room2",
        ]) );
      create_door("west","east",
            ([  "keyword" : ({"gate"}),
                "name"    : "Iron gate",
                "c_name"  : "��դ��",
                "c_desc"  : "����һ�������ִ���������դ��",
                "status"  : "locked",
                "lock"    : "JAIL_DOOR",
                ]) );

      create_door("north","south",
            ([  "keyword" : ({"north door","door"}),
                "name"    : "Iron door",
                "c_name"  : "��դ��",
                "c_desc"  : "����һ�������ִ���������դ��",
                "status"  : "locked",
                "lock"    : "JAIL_DOOR",
                ]) );

      create_door("south","north",
            ([  "keyword" : ({"south door","door"}),
                "name"    : "Iron door",
                "c_name"  : "��դ��",
                "c_desc"  : "����һ�������ִ���������դ��",
                "status"  : "locked",
                "lock"    : "JAIL_DOOR",
                ]) );
        
        reset();
}

