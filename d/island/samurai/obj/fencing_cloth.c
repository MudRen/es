#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "fencing clothes", "剑术道服 ");
        add( "id", ({ "cloth","clothes" }) );
        set_short("fencing clothes", "剑术道服");
        set_long(@AAA
一个练剑道人所穿的道服，是用厚麻布所织成，拥有不错的防护力
AAA
        );
        set( "unit", "件"); 
        set( "type", "body" );
        set( "armor_class", 20 );
        set( "defense_bonus", 2 );
        set("material","cloth");
        set( "weight", 130 );
        set( "value", ({ 600, "silver
        " }) );
}
