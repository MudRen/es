#include "goomay.h"
inherit DOORS;
inherit ROOM;

void create()
{
        ::create() ;
        set_short("�η�" );
        set_long(
@LONG
�����ǲ����ǹط��˵ĵط������˰��ķ��˶����������򵥵���
�η���ֻ��һ�ŵ����̳ɵĴ����η��г����ù������������Ϣ��������
������ģ������ֲ������Ͽ��ȥ��
LONG
        );
        
        set( "exits", ([ 
		"south" : Goomay"jail",
        ]) );
        set( "objects", ([
                "prisoner1" : Mob"prisoner1",
                "prisoner2" : Mob"prisoner1",
        ]) );
        
        set("c_item_desc",(["bed":"һ�ż򵥵ĵ��ݴ���\n" ]));

      create_door("south","north",
            ([  "keyword" : ({"door","gate"}),
                "name"    : "Iron door",
                "c_name"  : "��դ��",
                "c_desc"  : "����һ�������ִ���������դ��",
                "status"  : "open",
                "lock"    : "JAIL_DOOR",
                ]) );

        reset();

}

