#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("beautiful cloth","Ư�����·�");
        add("id",({"cloth"}) );
         set_short( "a beautiful cloth","Ư�����·�");
	set_long(
"This is a a beautiful cloth.\n"
"����һ��Ư�����·�\n"
	);
	set( "unit", "��" );
	set( "weight", 150 );
	set( "type", "body" );
	set( "material", "cloth" );
	set( "armor_class", 18 );
	set( "defense_bonus", 2 );
	set( "special_defense", ([ "divine":3, "fire":-5 ]) );
	set( "value", ({ 1420, "silver" }) );
}
