#include "../dgnisld.h"

inherit OBJECT;

void create()
{
        set_name( "Dragon ball", "龙珠" );
        add( "id", ({ "ball" , "dragon ball" ,}) );
        set_short( "Dragon ball", "龙珠");
        set_long(
            "This is the Dragon ball in old legend. \n",
            "这就是传说中的龙珠。它散发出微弱的光芒，很像一颗夜明珠。\n"
            "在它里面隐隐的可以看到五颗小星。\n");
        set("weight", 5 );
        set("prevent_insert",1);
        set("value", ({ 1 , "gold" }) );
        set("dgnball", 1);
        set("unit", "颗");
}           
