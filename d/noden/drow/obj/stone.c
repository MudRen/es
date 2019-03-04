#include <mudlib.h>

inherit OBJECT;

void create()
{
    set_name("stone of snake's eye","蛇眼之石");
    add("id",({"stone"}) );
    set_short("蛇眼之石");
    set_long(
@C_LONG
与其说这是一颗石头，不如说这是像是一颗蛇的眼睛，它随时都
闪烁著一股异样的蓝光，可能有什麽特殊的作用。　　
C_LONG
            );
    set("unit","颗");
    set("weight",25); 
    set("value", ({ 200, "silver" }));
    set( "no_sale",1); 
}    
