#include "../saulin_temple.h"
inherit ARMOR;

void create()
{
        set_name("eagle helmet", "飞鹰之盔");
        add( "id", ({ "helmet" }) );
        set_short("飞鹰之盔");
        set_long(@C_LONG
这是一顶由雪鹰皮做成的头盔，相传具有良好的防热能力。 
它是一顶纯白的皮盔，上面镶著一只小小的银鹰。 
C_LONG
        );
        set("unit","顶");
        set( "type", "head" );
        set( "material", "leather");
        set( "armor_class", 6 );
        set( "defense_bonus", 3 );
        set( "special_defense",
               ([ "fire":8, "cold":-3, "electric":-5 ]) );
        set( "weight", 100 );
        set( "value", ({ 240, "gold" }) );
}