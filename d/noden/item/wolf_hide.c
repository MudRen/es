#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "wolf hide", "��Ƥ����" );
	add( "id", ({ "hide" }) );
   set_short( "��Ƥ����" );
	set_long(
		"����һ����������Ƥ���ɵ����磬��֪���������Ե��������ǣ������\n"
		"���������紩��\n"
	);
	set( "unit", "��" );
	set( "type", "cloak" );
	set( "material", "leather");
	set( "armor_class", 7 );
	set( "weight", 140 );
	set( "value", ({ 450, "silver" }) );
}
