#include "mudlib.h"
inherit ARMOR;

void create()
{
    set_name( "long skirt", "��ɫ����ҷ�س�ȹ");
        add( "id", ({ "skirt" }) );
   set_short( "��ɫ����ҷ�س�ȹ");
        set_long(
                "����һ������Ȼ��˿֯�ɵ�ҷ�ذ�ɫ���ﳤȹ��\n"
        );
        set( "unit", "��");
        set( "type", "legs" );
        set( "armor_class", 8 );
        set("material","cloth");
        set( "defense_bonus", 2 );
        set( "weight", 70 );
   set( "wedding_obj", 1 );
	set("no_sale",1);
   set( "value", ({ 3250, "silver" }) );
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
