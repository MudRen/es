#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name( "visitors", "一大群观光旅客" );
	set_short( "一大群观光旅客" );
	set_long(@C_LONG
这是从外地来这里观光的旅客，看他们尽情挥洒金钱的样子，一个胜过一个，一个
又赛似一个，吵吵嚷嚷，不知是打那儿来，好像是暴发户一般，令你顿生厌恶之感
。
C_LONG
        );
        set( "wealth/silver",300);
        set( "alignment",-1000);
        set( "unit","");
        set( "gender","neuter");
        set_natural_armor(75,0); 
        set_natural_weapon( 27,14,28 );
}
