#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("gold plate","������");
        add("id",({"plate","platemail"}) );
         set_short( "a gold plate","������");
	set_long(
"This is a suit of plate make of gold ,which can  \n"
"protect your body against opponent's attacks.\n",
"����һ���ɻƽ���������,���Ա�����ֿ����˵Ĺ���\n"
	);
	set( "unit", "��" );
	set( "weight", 400 );
	set( "type", "body" );
	set( "armor_class", 32 );
	set( "defense_bonus", 0 );
	set( "material", "heavy_metal" );
	set( "value", ({ 680, "gold" }) );
}
