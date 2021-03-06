#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "Mother Hsin", "刑大娘" );
	add( "id", ({ "mother", "hsin", "mother hsin" }) );
	set_short( "刑大娘" );
	set_long(
		"刑大娘是刑老爹从东方大国避祸到蓝沙後, 因仰慕刑老爹济世救\n"
		"人的义行, 自愿帮忙照顾病患, 於是两人日久生情, 结为连理。\n"
		"现在刑大娘除了照顾病患外, 还兼卖一些医疗用品。\n"
	);
	set( "race", "human" );
	set( "gender", "female" );
	set_perm_stat( "int", 28 );
        set_perm_stat( "pie", 22 );
        set_perm_stat( "con", 22 );
        set_perm_stat( "kar", 27 );
	set_skill( "dodge", 95 );
	set_skill( "dagger", 95 );
	set_skill( "anatomlogy", 95 );
	set( "aiming_loc", "vascular" );
	set( "max_hp", 500 );
	set( "hit_points", 500 );
         set_natural_armor( 30, 10 );
	set_natural_weapon( 45, 20, 30 );
	set( "special_defense", ([ "all": 50,"none":60]) );
        set( "aim_difficulty",([ "weakest":10,"vascular":15 ]) );
	set( "alignment", 1400 );
	wield_weapon( "/d/healer/building/weapons/topknot" );
        equip_armor( "/d/healer/building/armors/jade_ring" );
}
