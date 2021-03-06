#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("red sandal beads","紫檀念珠");
    add("id",({"bead","beads","sandal"}) );
    set_short( "red sandal beads","紫檀念珠");
	set_long(
"This is a holy-ball necklace \n"
"这是一串由万年紫色檀香木做成的念珠, 相传是佛陀用过的念珠, 由於使用很久,\n"
"看起来很旧了, 但是它飘散出一股神秘的香味, 让你觉得使用起来很安心。\n"
	);
	set( "no_sale",1);
	set( "unit", "串" );
	set( "weight", 17 );
	set( "type", "misc" );
    set( "material", "wood");
	set( "armor_class", 0 );
	set( "defense_bonus", 10 );
	set( "value", ({ 100, "gold" }) );
}
