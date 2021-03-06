#include "../../story.h"

inherit SMOB"s_army";

void create()
{
	::create();
	set_level(13);
	set_name( "gate guard", "城门守卫" );
	add( "id", ({ "guard" }) );
	set_short( "城门守卫" );
	set_long(@C_LONG
城门守卫是负责「巫咸国」的安全工作的重要一员之一。虽然他一个人的力量不怎
样，但是，他们却重於团结，往往给来袭的敌人一个重重的痛击。
C_LONG
        );
	set( "gender", "male" );
	set( "alignment", 600 );
        set( "weight",1000);
        set_perm_stat( "str", 20 );
        set_perm_stat( "dex", 17 );
        set_skill( "parry", 75 );
        set_skill( "block", 75 );
        set_skill( "polearm", 60 );
        set_natural_armor(50,11);
        set("wealth/gold",20);
        wield_weapon(SWWEA"polearm1");
        equip_armor(SWARM"wiz_shield1");
}
