#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "Amulet of Dragon", "��֮����" );
	add( "id", ({ "amulet", }) );
	set_short( "��������" );
	set_long(
		"����һ���������������¡�\n"
	);
	set( "unit", "��" );
	set( "type", "misc" );
	set( "material" ,"cloth" );
        set( "defense_bonus", 2 );
        set( "special_defense", ([ "fire":3 ]) );
	set( "extra_look", "$N�����������������¡�\n" );
	set( "no_sale", 1 );
	set( "weight", 15 );
	set( "value", ({ 100, "silver" }) );
}
