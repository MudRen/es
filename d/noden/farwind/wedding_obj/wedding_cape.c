#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name("wedding cape", "��ɫ��������");
        add( "id", ({ "cape" }) );
   set_short("��ɫ��������");
        set_long(
                "һ��������˿���ߵİ�ɫ��������.\n" 
        );
        set("unit","��");
        set( "type", "cloak" );
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set("material","cloth");
        set( "weight", 65 );
   set( "wedding_obj", 1 );
	set("no_sale",1);
   set( "value", ({ 3000, "silver" }) );
   set( "extra_stats", ([ "dex": -2 ]) );
}

stop_equip(object owner)
{
        if ( (string)this_player()->query("gender") != "female") {
        printf(
                  "����Ц��, ���뵱������?\n" );
        return 1;
        }
}
