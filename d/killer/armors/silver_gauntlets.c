#include <mudlib.h>

inherit ARMOR;

string C_NAME="天蚕丝手套";

void create()
{
	set_name( "silver gauntlets", C_NAME );
	add( "id", ({ "gauntlets" }) );
	set_short( C_NAME );
	set_long(
		"一双闪亮的银色手套，这双手套是诺达尼亚王室的特约工匠麦尔\n"
		"迪蓝的精心杰作，他曾经很自豪地向人们说过，这双手套的防御\n"
		"力除了附上魔法以外，已经无法再更强了。\n"
	);
	set( "unit", "双" );
	set( "type", "hands" );
	set( "material", "knight" );
	set( "armor_class", 5 );
	set( "extra_skills", ([ "parry" :10 ]) );
	set( "weight", 80 );
	set( "value", ({ 210, "gold" }) );
	set( "no_sale", 1);
}
