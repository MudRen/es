#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "fur skirt", "��Ƥȹ��" );
	add( "id", ({ "skirt" }) );
   set_short( "��Ƥȹ��" );
	set_long(
		"����һ���������Ƥȹ�ӣ������ëƤ����һ�飬��ͺһ�飬ʮ���ѿ���\n"
	);
	set( "unit", "��" );
	set( "type", "legs" );
	set( "material", "leather" );
	set( "weight", 60 );
	set( "armor_class", 3 );
	set( "defense_bonus", 1 );
	set( "special_defense", ([ "fire":-2, "cold":1 ]) );	
	set( "value", ({ 170, "silver" }) );
}
