#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("Dwarvern mithril chainmail","�������������");
        add("id",({"chainmail"}) );
         set_short( "a dwarvern mithril chainmail","�������������");
	set_long(
"This is a suit of chainmail made of mithril meterial,which can  \n"
"protect your body against opponent's attacks.\n",
"����һ���������������ġ���,���Ա�����ֿ����˵Ĺ���\n"
	);
	set( "unit", "��" );
	set( "weight", 230 );
	set( "type", "body" );
	set( "material", "light_metal");
	set( "armor_class", 20 );
	set( "defense_bonus", 0 );
	set( "value", ({ 200, "gold" }) );
}
