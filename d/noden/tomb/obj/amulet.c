#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "amulet", "�����" );
   set_short( "֩�뻤���" );
	set_long(
		"����������һ��֩����״��С����������װ������ֵ�ҩ�ۻ�����֮��\n"
		"�Ķ������������ܴ̱ǡ�\n"
	);
	set( "type", "misc" );
	set( "material", "cloth" );
	set( "weight", 7 );
	set( "armor_class", 0 );
	set( "defense_bonus", 3 );
	set( "special_defense", ([ "poison":2, "fire":-2 ]) );
	set( "value", ({ 290, "silver" }) );
}
