#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "Steel Pot", "��մ��" );
	add( "id", ({ "pot" }) );
	set_short( "a pot", "��մ��" );
	set_long(
		"??\n",
		"���������ĳ�����û���������ؽ����Ƴɵ�\n"
	);
	set( "unit", "��" );
	set( "type", "shield" );
	set( "material", "light_metal" );
	set( "armor_class", 5 );
	set( "special_defense", ([ "mental":5 ]) );
	set( "weight", 150 );
	set( "value", ({ 500, "silver" }) );
}
