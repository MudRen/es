#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name("wedding boots", "��ͷƤЬ");
        add( "id", ({ "boots" }) );
   set_short("��ͷƤЬ");
        set_long(
                "һ˫�ڵķ����ļ�ͷƤЬ��\n"
        );
        set( "unit", "˫");
        set( "type", "feet" );
        set( "material" , "leather" ) ; 
        set( "armor_class", 8 );
        set( "defense_bonus", 2 );
   set( "wedding_obj", 1 );
        set( "no_sale", 1 );
        set( "weight", 100 );
   set( "value", ({ 3000, "silver" }) );
   set( "extra_stats", ([ "dex": -2 ]) );
}

stop_equip(object owner)
{
   if ( (string)this_player()->query("gender") != "male") {printf(
         "����Ц��, ���뵱��������?\n" );
   return 1;
   }
}
