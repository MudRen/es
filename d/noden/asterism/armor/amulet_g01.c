#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("small gold amulet", "黄金锁片");
        add( "id", ({ "amulet" }) );
        set_short( "黄金锁片");
        set_long(
                " 一个地精用来为孩子祈寿延命之用的黄金锁片。\n"
        );
        set("unit","个");
        set( "type", "misc" );
        set("material", "light_metal") ;
        set( "armor_class", 0 );
        set( "defense_bonus", 2 );
        set( "weight", 5 );
        set( "value", ({ 5, "gold" }) );
}



