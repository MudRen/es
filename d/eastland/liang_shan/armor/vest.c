#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("cell vest","���Ӳ�����");
    add("id",({"cell","vest"}) );
    set_short( "cell vest","���Ӳ�����");
	set_long(
		"This is a suit of vest \n",
		"����һ�����ӻ��Ƶ�С���ģ�\n"
		
	);
	set( "unit", "��" );
	set( "weight", 50 );
	set( "type", "body" );
	set( "armor_class", 20 );
        set("material","cloth");
	set( "defense_bonus", 3 );
	set( "value", ({ 90, "gold" }) );
}
