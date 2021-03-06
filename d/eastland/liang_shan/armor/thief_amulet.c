#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("twilight amulet", "黎明护身符");
        add( "id", ({ "amulet" }) );
        set_short("twilight amulet", "黎明护身符");
        set_long(
                "这是一个保护夜行人不受毒虫及邪魅侵害的护身符\n"
        );
        set( "unit", "个");
        set( "type", "misc" );
        set( "material", "cloth");
        set( "armor_class", 0);
        set( "defense_bonus", 5 );
        set( "special_defense",
             ([ "evil":10, "poison":10 ]) );
        set( "weight", 30 );
        set( "value", ({ 570, "silver" }) );
}
