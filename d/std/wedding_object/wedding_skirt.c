#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name( "wedding skirt", "��ɫ����ҷ�س�ȹ");
        add( "id", ({ "skirt" }) );
        set_short( "a wedding skirt", "��ɫ����ҷ�س�ȹ");
        set_long(
                "A white wedding skirt made of white silk.\n",
                "����һ������Ȼ��˿֯�ɵ�ҷ�ذ�ɫ���ﳤȹ��\n"
        );
        set( "unit", "��");
        set( "type", "legs" );
        set( "armor_class", 8 );
        set("material","cloth");
        set( "defense_bonus", 2 );
        set( "weight", 70 );
	set("no_sale",1);
        set( "value", ({ 60, "gold" }) );
}
