#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("swallowtail","��β���");
        add("id",({"suit"}) );
   set_short( "������β��");
        set_long(
"����һ����ɫ����β�������׵���ɫ��������Ͼ�İ��顣\n"
        );
        set( "unit", "��" );
        set( "weight", 150 );
        set( "type", "body" );
        set("material","cloth" ) ;
        set( "armor_class", 28 );
        set( "defense_bonus", 5 );
   set( "wedding_obj", 1 );
        set( "no_sale", 1 );
   set( "value", ({ 3180, "silver" }) );
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
