#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("Dwarvern mithril plate","��������������");
        add("id",({"plate","platemail"}) );
         set_short( "a dwarvern mithril plate","��������������");
	set_long(
"This is a suit of plate made of mithril meterial,which can  \n"
"protect your body against opponent's attacks.\n",
"����һ��������������������,���Ա�����ֿ����˵Ĺ���\n"
	);
	set( "unit", "��" );
	set( "weight", 300 );
	set( "type", "body" );
	set( "material", "light_metal" );
	set( "armor_class", 27 );
	set( "defense_bonus", 0 );
	set( "value", ({ 120, "gold" }) );
}
