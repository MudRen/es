#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("Silk cloth","˿���·�");
        add("id",({"cloth"}) );
         set_short( "Silk cloth","˿���·�");
	set_long(
"This is a suit of cloth made of silk meterial. \n"
"����һ��˿���·�.\n"
	);
	set( "unit", "��" );
	set( "weight", 150 );
	set( "type", "body" );
	set( "material", "cloth" );
	set( "armor_class", 16 );
	set( "defense_bonus", 5 );
	set( "special_defense", ([ "evil":4, "divine":-6 ]) );
	set( "value", ({ 187, "gold" }) );
}
