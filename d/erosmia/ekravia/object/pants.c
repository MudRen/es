
#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black pants", "黑长裤" );
	add( "id", ({ "pants", "black pants" }) );
   set_short( "黑长裤" );
	set_long( @LONG
这是一件棉质的黑色长裤, 大多被用来搭配正式礼服。
LONG
	);
	set( "unit", "件" );
	set( "type", "legs" );
	set( "material", "cloth");
	set( "armor_class", 5 );
	set( "weight", 20 );
	set( "value", ({ 300, "silver" }) );
}
