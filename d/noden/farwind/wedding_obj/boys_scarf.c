#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name("wedding scarf", "丝质领巾");
        add( "id", ({ "scarf" }) );
   set_short("丝质领巾");
        set_long(
                "一条男士在正式场合结的领巾。\n"
        );
        set("unit","条");
        set( "type", "cloak" );
        set( "material","cloth" ) ;
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "weight", 55 );
   set( "wedding_obj", 1 );
        set( "no_sale", 1 );
        set( "value", ({ 1800, "silver" }) );
   set( "extra_stats", ([ "dex": -2 ]) );
}

stop_equip(object owner)
{
        if ( (string)this_player()->query("gender") != "male") {
        printf(
                  "别开玩笑了, 你想当男人婆吗?\n" );
        return 1;
        }
}
