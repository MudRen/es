#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "flinty shield", "��ʯ��" );
	add( "id", ({ "shield" }) );
	set_short( "��ʯ��" );
	set_long(
		"����һ���ð���ɫ��ʯ���ɵĶܣ������������ء�\n"
	);
	set( "unit", "��" );
	set( "type", "shield" );
	set( "material", "stone");
	set( "armor_class", 5 );
	set( "defense_bonus", 3 );
	set( "special_defense", ([ "fire":3, "electric":-2 ]) );
	set( "weight", 190 );
	set( "value", ({ 570, "silver" }) );
}
