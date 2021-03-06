#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "Five-Color In", "五色印" );
	add( "id", ({ "shield","in" }) );
	set_short( "五色印" );
	set_long( 
@C_LONG
这是一颗漂亮的印石，上面闪耀著五种颜色的光芒。红、绿、蓝、白、黄色的光辉
交互闪烁著，令你目不暇给。
C_LONG
	);
	set( "unit", "颗" );
	set( "type", "shield" );
	set( "material", "stone");
	set( "armor_class", 8 );
	set( "defense_bonus", 6 );
	set( "special_defense",
	     ([ "none":5, "evil":5 ]) );
	set( "extra_skills",([ "block":7 ]) );     
	set( "weight", 50 );
	set( "no_sale", 1);
	set( "value", ({ 4750, "silver" }) );
}
