
#include <mudlib.h>

inherit ARMOR;

string C_NAME="天蚕茧盾";

void create()
{
	set_name( "silver shield", C_NAME );
	add( "id", ({ "shield" }) );
	set_short( C_NAME );
	set_long(
		"一面闪亮的银色盾牌，这面盾牌是诺达尼亚王室的特约工匠麦尔\n"
		"迪蓝的精心杰作，他曾经很自豪地向人们说过，这面盾牌的防御\n"
		"力除了附上魔法以外，已经无法再更强了。\n"
	);
	set( "unit", "面" );
	set( "type", "shield" );
	set( "material" ,"knight");
	set( "armor_class", 10 );
	set( "extra_skills", ([ "block":10 ]) );
	set( "weight", 100 );
	set( "value", ({ 270, "gold" }) );
	set( "no_sale", 1);
}
