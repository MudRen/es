#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name( "wedding pants", "长裤");
        add( "id", ({ "pants" }) );
   set_short( "新郎礼服的长裤");
        set_long(
                "这是一件由天山蚕丝织成的长裤。\n"
        );
        set( "unit", "条");
        set( "type", "legs" );
        set( "material","cloth" ) ;
        set( "armor_class", 8 );
        set( "defense_bonus", 2 );
        set( "weight", 30 );
   set( "wedding_obj", 1 );
        set( "no_sale", 1 );
   set( "value", ({ 3620, "silver" }) );
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
