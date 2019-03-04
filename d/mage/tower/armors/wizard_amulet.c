#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "wizard's amulet", "��ʦ�����" );
	add( "id", ({ "amulet" }) );
	set_short( "a wizard's amulet", "��ʦ�����" );
	set_long(
		"This is Rashudi's magical amulet. You can see many symbols\n"
		"of magical shield on it.\n",
		"�������������޵��������ߵģ����滭���˸���ħ�����������ġ�\n"
	);
	set( "unit", "��" );
	set( "type", "misc" );
	set( "material", "cloth" );
	set( "defense_bonus", 10 );
	set( "special_defense",
	     ([ "fire":10, "cold":10, "electric":5, "energy":5 ]) );
	set( "extra_skills", ([ "meditate":10 ]) );     
	set( "no_sale", 1);
	set( "weight", 5 );
	set( "value", ({ 5500, "silver" }) );
}
