#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name("wedding boots", "��ɫ����Ь");
        add( "id", ({ "boots" }) );
   set_short( "��ɫ����Ь" );
        set_long(
		 "����һ˫�ɴ�˿�Ƴɵİ�ɫ����Ь��������ʮ�ָ��Ŵ󷽡�\n"
        );
        set( "unit", "˫");
        set( "type", "feet" );
        set("material","cloth");
        set( "armor_class", 8 );
        set( "defense_bonus", 2 );
   set( "wedding_obj", 1 );
	set("no_sale",1);
        set( "weight", 100 );
   set( "value", ({ 3450, "silver" }) );
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
