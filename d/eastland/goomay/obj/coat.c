#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "leather coat", "Ƥ����" );
	add( "id", ({ "coat" }) );
	set_short( "a leather coat", "Ƥ����" );
	set_long(
		"This coat is covered with dirt and has a stink smell.\n",
		"���Ƥ�������������������գ�����һ��ŨŨ�ľƳ�ζ��\n"
	);
	set( "unit", "��" );
	set( "type", "cloak" );
        set("material","leather");
	set( "armor_class", 5 );
	set( "weight", 40 );
	set( "value", ({ 120, "silver" }) );
}
