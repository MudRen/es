#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("wedding suit","��ɫ�������");
        add("id",({"suit"}) );
   set_short( "��ɫ�������");
	set_long(
"����һ����ɫ��������������׵���ɫ��������Ͼ�İ��顣\n"
	);
	set( "unit", "��" );
	set("material","cloth");
	set( "weight", 150 );
	set( "type", "body" );
	set( "armor_class", 28 );
	set( "defense_bonus", 5 );
   set( "wedding_obj", 1 );
	set("no_sale",1);
   set( "value", ({ 3500, "silver" }) );
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
