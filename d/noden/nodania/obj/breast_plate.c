#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "steel breastplate", "���ؼ�" );
	add( "id", ({ "plate", "breastplate" }) );
	set_short( "���ؼ�" );
	set_long(
		"һ����������ҫ�۵ĸ����ؼס�\n"
	);
	set( "unit", "��" );
	set( "type", "body" );
	set( "material", "heavy_metal");
	set( "armor_class", 28 );
	set( "weight", 280 );
	set( "value", ({ 1970, "silver" }) );
}
