#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "amulet of Cybilas", "护身符" );
	add( "id", ({ "amulet" }) );
	set_short( "赛比拉斯护身符" );
	set_long(@C_LONG
这个护身符上闪烁著一点一点蓝色的白光，像天空中最耀眼的星星，当你将它
握在手中的时候，可以感觉到它点温暖。
C_LONG
        );
	set( "type", "misc" );
	set( "material" ,"element");
	set( "armor_class", 0 );
	set( "defense_bonus", 8 );
	set( "special_defense", 
	      ([ "acid":5, "fire":5, "evil":-2 ]) );
	set( "weight", 15 );
	set( "value", ({ 205, "gold" }) );
}
