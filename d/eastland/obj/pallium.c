#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "pallium", "ɮ��" );
   set_short( "ɮ��" );
	set_long(
		"����һ������ͨ�ĺ��д����಼ɮ�ۡ�\n"
	);
	set( "unit", "��" );
	set( "type", "body" );
	set( "material", "cloth" );
	set( "armor_class", 1 );
	set( "defense_bonus", 3 );
	set( "weight", 50 );
	set( "value", ({ 270, "silver" }) );
}
