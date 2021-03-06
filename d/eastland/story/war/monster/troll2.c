#include "../../story.h"
inherit WMOB"warmob";

void create()
{
	::create();
	set_level(17);
	set_name( "Troll warrior", "巨人族战士" );
	add( "id", ({ "warrior","troll" }) );
	set_short( "巨人族战士" );
	set_long(@LONG
一位凶猛的巨人族战士。他全身青筋暴现，一双黑拗拗的粗壮手臂，不下千百个疤
痕。
LONG
	);
	set( "unit", "位" );
	set( "weight",1300);
        set( "race","巨人");
	set( "gender","male");
	set( "alignment", -500 );
	set_natural_armor(60,30);
	set_natural_weapon(3,4,4);
	set_temp("detect_invi",1);
	set_perm_stat("str",28);
	set_perm_stat("dex",24);
	set_perm_stat("kar",25);
	set_perm_stat("int",10);
	set( "wealth/silver", 500 );
	set( "killer", 1 );
        set( "war_points", 150 );
	equip_armor(WARM"cloth1");
	wield_weapon(WWEA"axe1");
	set_skill( "axe", 100 );
	set_skill( "parry", 100 );
}
