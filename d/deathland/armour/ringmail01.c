#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("Dwarvern mithril ringmail","������������");
        add("id",({"ringmail"}) );
         set_short( "a dwarvern mirhril ringmail","������������");
	set_long(
"This is a suit of ringmail made of mithril meterial,which can  \n"
"protect your body against opponent's attacks.\n",
"����һ���������������Ļ���,���Ա�����ֿ����˵Ĺ���\n"
	);
	set( "unit", "��" );
	set( "weight", 220 );
	set( "type", "body" );
	set( "material", "light_metal" );
	set( "armor_class", 20 );
	set( "defense_bonus", 0 );
	set( "value", ({ 87, "gold" }) );
}
