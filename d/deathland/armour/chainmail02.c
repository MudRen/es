#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("Ironsteel chainmail","���֡���");
        add("id",({"chainmail"}) );
         set_short( "a ironsteel chainmail","���֡���");
	set_long(
"This is a suit of chainmail made of iron steel,which can  \n"
"protect your body against opponent's attacks.\n",
"����һ����������ġ���,���Ա�����ֿ����˵Ĺ���\n"
	);
	set( "unit", "��" );
	set( "weight", 300 );
	set( "type", "body" );
	set( "material", "heavy_metal" );
	set( "armor_class", 22 );
	set( "defense_bonus", 0 );
	set( "value", ({ 1470, "silver" }) );
}
