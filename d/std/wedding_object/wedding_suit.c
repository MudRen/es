#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("wedding suit","��ɫ�������");
        add("id",({"suit"}) );
         set_short( "a wedding suit","��ɫ�������");
	set_long(
"This is a suit of wedding suit made of true white silk meterial.\n",
"����һ����ɫ��������������׵���ɫ��������Ͼ�İ��顣\n"
	);
	set( "unit", "��" );
	set("material","cloth");
	set( "weight", 150 );
	set( "type", "body" );
	set( "armor_class", 28 );
	set( "defense_bonus", 5 );
	set("no_sale",1);
	set( "value", ({ 318, "gold" }) );
}
