#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name( "wedding pants", "����");
        add( "id", ({ "pants" }) );
   set_short( "��������ĳ���");
        set_long(
                "����һ������ɽ��˿֯�ɵĳ��㡣\n"
        );
        set( "unit", "��");
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
                  "����Ц��, ���뵱��������?\n" );
        return 1;
        }
}
