#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name("wedding lace", "��ɫ����ͷɴ");
        add( "id", ({ "lace" }) );
   set_short( "��ɫ����ͷɴ");
        set_long(
		 "�����ô��׵���˿���ɵ�����ͷɴ�����滹׺�������ɫ��õ�塣\n"
        );
        set("unit","��");
        set("material","cloth");
        set( "type", "head" );
        set( "armor_class", 8 );
        set( "defense_bonus", 0 );
        set( "weight", 10 );
   set( "wedding_obj", 1 );
	set( "no_sale",1);
   set( "value", ({ 2800, "silver" }) );
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

