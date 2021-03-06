#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("brass dauist hat", "黄铜道冠");
        add( "id", ({ "hat" }) );
        set_short( "brass dauist hat", "黄铜道冠");
        set_long(
                "A brass hat 6used by dauists .\n",
                "每个道士头上都有的装饰物，但不知有没有防御功能． \n"
        );
        set("unit","顶");
        set( "type", "head" );
        set( "material", "light_metal");
        set( "armor_class", 4 );
        set( "defense_bonus", 1 );
        set( "special_defense",
               ([ "evil":5, "divine":-4, "mental":5 ]) );
        set( "weight", 60 );
        set( "value", ({ 22, "gold" }) );
}



