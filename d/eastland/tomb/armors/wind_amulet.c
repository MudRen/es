#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "wind amulet", "��֮����" );
	add( "id", ({ "amulet" }) );
	set_short( "��֮����" );
	set_long(
		"����һ������Ļ�������ҫ��ǳ��ɫ�Ĺ�â������Ը��ܵ���������������\n"
	);
	set( "unit", "��" );
	set( "type", "misc" );
	set( "material", "cloth" );
	set( "defense_bonus", 5 );
	set( "special_defense",
	     ([ "evil":15, "divine": -10 ]) );
	set( "weight", 5 );
	set( "value", ({ 1100, "silver" }) );
}
