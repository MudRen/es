#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "alloyed shield", "�Ͻ��" );
	add( "id", ({ "shield" }) );
	set_short( "an alloyed shield", "�Ͻ��" );
	set_long(
		"You see an alloyed shield. It looks pretty heavy and\n"
		"can supply good protection.\n",
		"����һ����ĳ�ֲ�֪���Ͻ����Ķܣ��������൱�ء�\n"
	);
	set( "unit", "��" );
	set( "type", "shield" );
	set( "material", "heavy" );
	set( "armor_class", 6 );
	set( "weight", 140 );
	set( "value", ({ 630, "silver" }) );
}
