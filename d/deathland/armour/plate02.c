#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("Dwarvern mithril full plate","��������������");
        add("id",({"plate","platemail"}) );
         set_short( "a dwarvern mithril full plate","��������������");
	set_long(
"This is a suit of full plate made of mithril meterial,which can  \n"
"protect your body against opponent's attacks.\n",
"����һ��������������������,���Ա�����ֿ����˵Ĺ���\n"
	);
	set( "unit", "��" );
	set( "weight", 350 );
	set( "type", "body" );
	set( "material", "light_metal" );
	set( "armor_class", 32 );
	set( "defense_bonus", 0 );
	set( "value", ({ 220, "gold" }) );
}
