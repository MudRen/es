#include "../farwind.h"

inherit ARMOR;

void create()
{
	set_name( "breast plate", "�ؼ�" );
	add( "id", ({ "plate" }) );
	set_short( "�ؼ�");
	set_long(
		"����һ�����Ƶ��ؼף����������ز��������ķ��ߡ�\n"
	);
	set( "unit", "��" );
	set( "weight", 150 );
	set( "type", "body" );
	set( "material", "heavy_metal");
	set( "armor_class", 20 );
	set( "defense_bonus", 0 );
	set( "value", ({ 67, "gold" }) );
}
