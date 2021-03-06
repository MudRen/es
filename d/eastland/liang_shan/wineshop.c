#include "takeda.h"
#include <money.h>

inherit ROOM;

void create()
{
        ::create() ;
        set("light", 1) ;
        set_short( "梁山酒店" );
        set_long(@LONG
这里是梁山泊最大的酒楼，山寨内的山贼和跑单帮买黑货的商人，经
常聚在这里享受孙二娘的美食以慰劳自己，顺便交换旅行的经历，几名店
小二忙进忙出的显得十分热闹，一阵阵的酒香，肉香扑鼻而来，你不禁觉
得饥肠辘辘，食指大动，低声向老板询问价钱(menu)。
LONG
        );
        
        set( "exits", ([ 
        	"east"  : TROOM"path2" ,
        ]) );
        
        set( "objects", ([
                "owner" : TMONSTER"zhan1",
                "owner_wife" : TMONSTER"sun1",
                "guest" : TMONSTER"traveller"
        ]) );
        reset();
}
int clean_up() { return 0; }
