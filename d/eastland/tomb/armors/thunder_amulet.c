#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "thunder amulet", "��֮����" );
	add( "id", ({ "amulet" }) );
	set_short( "��֮����" );
	set_long(
		"����һ������Ļ�������ҫ�����ɫ�Ĺ�â������Ը��ܵ���������������\n"
	);
	set( "unit", "��" );
	set( "type", "misc" );
	set( "material", "cloth" );
	set( "defense_bonus", 5 );
	set( "special_defense",
	     ([ "electric":15, "mental": -10 ]) );
	set( "weight", 5 );
	set( "value", ({ 1300, "silver" }) );
}
