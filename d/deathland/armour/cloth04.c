#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("poet's cloth","ʫ��֮��");
        add("id",({"cloth"}) );
         set_short( "poet's cloth","ʫ��֮��");
	set_long(
"This is a poet's cloth . \n"
"����һ��ʫ��ר�õ��·�\n"
	);
	set( "unit", "��" );
	set( "weight", 70 );
	set( "type", "body" );
	set( "material", "cloth" );
	set( "armor_class", 10 );
	set( "defense_bonus", 2 );
	set( "special_defense", ([ "mental":2, "fire":-2, "acid":-2 ]) );
	set( "value", ({ 420, "silver" }) );
}
