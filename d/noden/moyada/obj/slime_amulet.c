#include "../moyada.h"

inherit ARMOR;

void create()
{
	set_name( "slime amulet", "�����" );
	add( "id", ({ "amulet" }) );
	set_short( "ʷ��ķ�����" );
	set_long(
		"����ʷ��ķ���ŵĻ������\n"
	);
	set( "unit", "��" );
	set( "type", "misc" );
	set( "material", "cloth" );
	set( "defense_bonus", 6 );
	set( "special_defense",
	      ([ "fire":5, "cold":5, "electric":-10, "acid":5, "energy":-5 ]) );
	set( "no_sale", 1);
	set( "weight", 5 );
	set( "value", ({ 10, "silver" }) );
}
