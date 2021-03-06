#include "goomay.h"

inherit ROOM;
inherit DOORS;
void create()
{
        ::create() ;
        set("light", 1) ;
        set_short( "捕房" );
        set_long(
@LONG
这里是捕快们休息办案的地方，本镇由於常有帮派人物出入，所以捕快也就
特别多，并且只要到了每年比武大赛，为了保护皇上，更会由各地抽调人手来帮
忙，所以捕头的责任就更加重了。不过现任的古梅镇总捕头是人称「追魂尺」的
段飞鹰，他一向主张严刑逼供，在他眼下，你最好还是乖乖的做良民吧。
LONG
        );
        
        set( "exits", ([ 
                "east" : Goomay"jail",
		"west" : Goomay"office",
        ]) );
        set( "objects", ([
                "master" : Mob"chief_cop",
        ]) );

      create_door("east","west",
            ([  "keyword" : ({"gate"}),
                "name"    : "Iron gate",
                "c_name"  : "铁栅门",
                "c_desc"  : "这是一扇有著粗大铁栏的铁栅门",
                "status"  : "locked",
		"lock"    : "JAIL_DOOR",
                ]) );


        reset();
}

