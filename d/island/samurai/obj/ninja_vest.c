#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "Ninja Vest", "忍者网甲");
        add( "id", ({ "ninja","vest"}) );
        set_short("Ninja Vest", "忍者网甲");
        set_long(@AAA
一件忍者们特有的防护衣，是将细的金属编织成网状，既保有
金属型铠甲的防护力，又有轻的重量，是少数忍者才能有的防
护衣
AAA
        );
        set( "unit", "件"); 
        set( "type", "body" );
        set( "armor_class", 30 );
        set( "defense_bonus", 3 );
        set("material","element");
        set( "weight", 100 );
        set( "value", ({ 1160, "silver" }) );
}
