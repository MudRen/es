#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "sandals", "��Ь" );
	add( "id", ({ "sandal" }) );
   set_short( "��Ь" );
	set_long(
		"һ˫��������Ϊ���ʵ���Ь��\n"
	);
	set( "unit", "˫" );
	set( "type", "feet" );
	set( "material", "leather");
	set( "armor_class", 1 );
	set( "weight", 15 );
	set( "value", ({ 26, "silver" }) );
}
