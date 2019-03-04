#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "long blue garb", "天蓝色长袍" );
	add( "id", ({ "garb" }) );
	set_short( "a long blue garb", "天蓝色长袍" );
	set_long(
		"You see a blue long garb.\n",
		"这是一件很普通的天蓝色长袍，就像是一般掌柜朝奉们常穿的那种。\n"
	);
	set( "unit", "件" );
        set("material","cloth");
	set( "type", "body" );
	set( "armor_class", 8 );
	set( "weight", 50 );
	set( "value", ({ 140, "silver" }) );
}
