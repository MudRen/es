#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "fur buskin", "��Ƥ��ѥ" );
	add( "id", ({ "buskin", "buskins" }) );
   set_short( "��Ƥ��ѥ" );
	set_long(
		"����һ˫�������Ƥ��ѥ��������Ƥ�����˺ü�Ȧ��\n"
	);
	set( "unit", "˫" );
	set( "type", "feet" );
	set( "material", "leather" );
	set( "weight", 40 );
	set( "armor_class", 2 );
	set( "defense_bonus", 1 );
	set( "special_defense", ([ "fire":-3, "cold":1 ]) );
	set( "value", ({ 260, "silver" }) );
}
