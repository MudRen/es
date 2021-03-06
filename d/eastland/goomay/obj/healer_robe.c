#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "healer's robe", "医生诊袍" );
	add( "id", ({ "robe" }) );
	set_short( "an healer's robe", "医生诊袍" );
	set_long(
		"You see a healer's robe.\n",
		"这是一件医生常穿的白色长袍，上面沾了一些斑斑点点的血迹。\n"
	);
	set( "unit", "件" );
        set("material","healer");
	set( "type", "body" );
	set( "weight", 80 );
	set( "armor_class", 20 );
	set( "value", ({ 150, "silver" }) );
}
