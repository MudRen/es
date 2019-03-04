#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "blue battle armor", "青衣战甲" );
	add( "id", ({ "battle armor", "armor" }) );
	set_short( "青衣战甲" );
	set_long(@C_LONG
这是一件巧匠设计的战甲，若岚宫禁卫军的制式护甲分为青、红、白
、黑四种，分别发给四种品级的武官。
C_LONG
	);
	set( "unit", "件" );
	set( "type", "body" );
	set( "material", "heavy_metal" );
	set( "weight", 240 );
	set( "armor_class", 24 );
	set( "defense_bonus", 4 );
	set( "value", ({ 1500, "silver" }) );
}
