#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "water amulet", "ˮ֮����" );
	add( "id", ({ "amulet" }) );
	set_short( "ˮ֮����" );
	set_long(
		"����һ������Ļ�������ҫ������ɫ�Ĺ�â������Ը��ܵ���������������\n"
	);
	set( "unit", "��" );
	set( "type", "misc" );
	set( "material", "cloth" );
	set( "defense_bonus", 5 );
	set( "special_defense",
	     ([ "cold":15, "fire": -10 ]) );
	set( "weight", 5 );
	set( "value", ({ 900, "silver" }) );
}
