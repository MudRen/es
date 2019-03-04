#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "Snow Clothes", "冰雪护袍");
        add( "id", ({ "snow","clothes" }) );
        set_short("Snow Clothes", "冰雪护袍");
        set_long(@AAA
这是一件雪白色的长袍，是用高级丝绸加上特殊材料混合织成的，能提供相
当高的防护力，而在袍子的边角还绣有红色的带子！！
AAA
        );
        set( "unit", "件"); 
        set( "type", "body" );
        set( "armor_class", 34 );
        set( "defense_bonus", 6 );
        set("material","cloth");
        set("special_defense",(["cold":-15,"fire":15]));
        set( "weight", 90 );
        set( "no_sale",1);
        set( "value", ({ 1600, "silver" }) );
}
