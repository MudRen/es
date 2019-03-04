//#pragma save_binary

#include "/d/noden/farwind/farwind.h"
#include <money.h>

inherit ROOM;
inherit "/std/seller";
inherit DOORS;

void create()
{
        ::create() ;
        set("light", 1) ;
        set_short( "С�Ƶ�" );
        set_long(@C_LONG
������Զ�����������ľƵ꣬����������ð�ռ���������
��Ϣ�����໻ȡ���Ƚ�Ǯ������ľ��顣����ʫ������������
�����ϵ����ɣ���¯�еĻ��յ����ҡ���ʱ��û��ʲ�����һ
���ҾƸ��õ��ˡ��Ͼ�����˶�֪��������Щʲ�ᣬ�����㻹
�ǿ��Ը��ϰ���Ҫ�ݲ˵�(menu)������!
C_LONG
        );
        
        set( "exits", ([ 
        	"south" : FARWIND"bazz1" ,
        ]) );
        set_inventory( ({
                       ({ FARWIND"items/ching.c", 10, 10}),
                       ({ FARWIND"items/xo.c", 10, 10}),
                       ({ FARWIND"items/rose.c", 10, 10}),
					   ({ FARWIND"items/vodka.c", 10, 10}),
					   ({ FARWIND"items/chicken.c", 10, 10}),
					   ({ FARWIND"items/special.c", 20, 20}),
        }) );
        create_door("south","north",
		 ([  "keyword" : ({"wooden","door"}),
		     "name"    : "wooden door",
		     "c_name"  : "ľ��",
		     "c_desc"  : "����һ�ȿɰ���Сľ�ţ����Ϲ���һ���Ƶ������",		
		     "status"  : "open",
		]) );

        set( "objects", ([
                "shop owner" : FARWIND"monster/wineshop_owner",
                "drunk": FARWIND"monster/drunk"
        ]) );
        reset();
}

void reset()
{
     room::reset() ;
     seller::reset() ;
     return ;
}
