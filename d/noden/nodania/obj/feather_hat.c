#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "feathered hat", "����ñ" );
	add( "id", ({ "hat" }) );
	set_short( "����ñ" );
	set_long(
		"�ⶥñ�ӵı߲߱���һ������ë��װ�Ρ�\n"
	);
	set( "unit", "��" );
	set( "type", "head" );
	set( "material", "leather");
	set( "armor_class", 3 );
	set( "weight", 30 );
	set( "value", ({ 120, "silver" }) );
}
