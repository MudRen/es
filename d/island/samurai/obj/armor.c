#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "ninja clothes", "忍者衣");
        add( "id", ({ "ninja","clothes"}) );
        set_short("ninja clothes", "忍者衣");
        set_long(@AAA
一件忍者们穿的防护衣，适用极轻的材质做成的，以方便人的行动，只
是因此也减少了防护力        

        );
        set( "unit", "件"); 
        set( "type", "body" );
        set( "armor_class", 16 );
        set( "defense_bonus", 2 );
        set("material","leather");
        set( "weight", 90 );
        set( "value", ({ 760, "silver" }) );
}
