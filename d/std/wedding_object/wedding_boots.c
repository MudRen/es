#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name("wedding boots", "��ɫ����Ь");
        add( "id", ({ "boots" }) );
        set_short("a pair of wedding boots", "��ɫ����Ь");
        set_long(
                "A pair of boots made for wedding.\n",
		 "����һ˫�ɴ�˿�Ƴɵİ�ɫ����Ь��������ʮ�ָ��Ŵ󷽡�\n"
        );
        set( "unit", "˫");
        set( "type", "feet" );
        set("material","cloth");
        set( "armor_class", 8 );
        set( "defense_bonus", 2 );
	set("no_sale",1);
        set( "weight", 100 );
        set( "value", ({ 2450, "silver" }) );
}
