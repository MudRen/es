#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name("silk wedding gloves", "��ɫ����");
        add( "id", ({"gloves" }) );
   set_short("��ɫ����");
        set_long(
                "һ˫˿�ʰ�ɫ���ף�רΪ������������ơ�\n"
        );
        set( "unit", "˫");
        set( "type", "hands" );
        set( "material" ,"cloth" ) ;
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "weight", 30 );
   set( "wedding_obj", 1 );
        set( "no_sale", 1 );
   set( "value", ({ 2880, "silver" }) );
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
