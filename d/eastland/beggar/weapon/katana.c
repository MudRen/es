#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "katana", "螺旋刃" );
        set_short( "螺旋刃" );
	set_long(@C_LONG
这是一把黑月最喜爱用的武器, 刃身呈螺旋状而且周围极其锋利,一不小心被它的
剑风扫到就非死即伤, 又因为拿在手上很轻几乎忘了它的存在,所以最适合杀手型
的战士用的。 
C_LONG	
	);
	set( "unit", "把" );
	set( "weight", 40 );
	setup_weapon("longblade",25,15,20);
	set( "value", ({ 1200, "silver" }) );
}

