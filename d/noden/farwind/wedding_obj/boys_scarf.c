#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name("wedding scarf", "˿�����");
        add( "id", ({ "scarf" }) );
   set_short("˿�����");
        set_long(
                "һ����ʿ����ʽ���Ͻ�����\n"
        );
        set("unit","��");
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
                  "����Ц��, ���뵱��������?\n" );
        return 1;
        }
}
