#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "alloyed visor helm", "�Ͻ���ͷ��" );
	add( "id", ({ "visor helm", "visor", "helm" }) );
	set_short( "an alloyed visor helm", "�Ͻ���ͷ��" );
	set_long(
		"You see an alloyed visor helm. It looks pretty heavy and\n"
		"can supply good protection.\n",
		"����һ����ĳ�ֲ�֪���Ͻ����ĸ���ͷ�����������൱�ء�\n"
	);
	set( "unit", "��" );
	set( "type", "head" );
	set( "material", "heavy_metal" );
	set( "armor_class", 6 );
	set( "weight", 80 );
	set( "value", ({ 580, "silver" }) );
}
