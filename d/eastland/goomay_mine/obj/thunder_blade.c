#include "../zeus.h"

inherit WEAPON;

void create()
{
	set_name("thunder blade", "雷霆刀");
	add ("id",({ "blade"}) );
	set_short("雷霆刀");
	set_long(@C_LONG
这把刀就是传说中，石家车队威震边疆时，石家好汉所配的制式武器。
在刀中因为掺了稀世的寒铁精华，所以无坚不摧，是把难得的好刀．
C_LONG
	);
	
	set( "unit", "把" );
	set_c_verbs( ({ "的%s使出－－石破天惊－－劈向%s", 
	                "的%s使出－－破釜沈舟－－斩向%s",
	                "的%s使出－－雷动天下－－横劈%s",
	                "的%s使出－－神龙九现－－直砍%s",}) );
 	set( "weapon_class", 33 );
	set( "type", "longblade" );
	set( "min_damage", 23 );
	set( "max_damage", 38 );
	set( "weight", 250 );
	set( "value", ({ 2100, "silver" }) );
}