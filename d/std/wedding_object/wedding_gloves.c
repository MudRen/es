#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name("silk wedding gloves", "��ɫ��˿��������");
        add( "id", ({"gloves" }) );
        set_short("a silk wedding gloves", "��ɫ��˿��������");
        set_long(
                "A wedding gloves made of silk.\n",
                "һ˫��Ȼ��˿֯�ɵİ�ɫ�������ס�\n"
        );
        set( "unit", "˫");
        set( "type", "hands" );
        set("material","cloth");
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "weight", 30 );
	set("no_sale",1);
        set( "value", ({ 1250, "silver" }) );
}
