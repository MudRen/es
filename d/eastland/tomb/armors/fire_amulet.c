#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "fire amulet", "��֮����" );
	add( "id", ({ "amulet" }) );
	set_short( "��֮����" );
	set_long(
		"����һ������Ļ�������ҫ������ɫ�Ĺ�â������Ը��ܵ���������������\n"
	);
	set( "unit", "��" );
	set( "type", "misc" );
	set( "material", "cloth" );
	set( "defense_bonus", 5 );
	set( "special_defense",
	     ([ "fire":15, "cold": -10 ]) );
	set( "weight", 5 );
	set( "value", ({ 1400, "silver" }) );
}
