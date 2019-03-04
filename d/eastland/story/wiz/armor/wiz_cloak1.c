#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("cloak of king", "王者披风");
        add( "id", ({ "cloak" }) );
        set_short( "王者披风");
        set_long(@C_LONG
这是一件象徵王者地位的披风，後面印有一个皇冠图形。  
C_LONG
        );
        set("unit","件");
        set("type", "cloak" );
        set("material","heavy_metal") ;
        set("armor_class",7);
        set( "defense_bonus",3);
        set("weight", 100 );
        set("value", ({ 310, "gold" }) );
}



