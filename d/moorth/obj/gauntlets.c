#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "alloyed gauntlets", "�Ͻ���" );
	add( "id", ({ "gauntlets" }) );
	set_short( "a pair of alloyed gauntlets", "�Ͻ���" );
	set_long(
		"You see a pair of alloyed gauntlets. It looks pretty heavy and\n"
		"can supply good protection.\n",
		"����һ˫��ĳ�ֲ�֪���Ͻ����Ļ��֣��������൱�ء�\n"
	);
	set( "unit", "˫" );
	set( "type", "hands" );
	set( "material", "heavy_metal");
	set( "armor_class", 5 );
	set( "weight", 80 );
	set( "value", ({ 760, "silver" }) );
}
