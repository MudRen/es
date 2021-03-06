#include "saulin_monka.c"

void create()
{
	::create();
	set_level(7);
	set_name( "Servant monk", "服事僧" );
	add( "id", ({ "monk", }) );
	set_short( "服事僧" );
	set_long(@C_LONG
他是一名年轻和尚，刚刚通过了禅学与武功\的基本测试，现在正
负责操持一些杂务，以熟悉各院各堂的事务。
C_LONG
	);
	set( "alignment", 100 );
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat( "str", 12 );
	set_perm_stat( "int", 18 );
	set_perm_stat( "kar", 14 );
	set_perm_stat( "dex", 10 );
	set_skill( "dodge", 56 );
	set("defense_type","dodge");
	set_skill( "unarmed",60);
	set( "wealth/silver", 10 );
	set( "max_hp", 220 );
	set( "hit_points", 220 );
	set("force_effect",2);
	set("max_fp", 550);
	set("attack_skill",FIST"long_fist");
        set("gonfus/long_fist",80);
	set("force_points", 550);
	set_natural_armor( 37, 15 );
	set_natural_weapon( 10, 6, 12 );
	equip_armor( SAULIN_OBJ"pallium" );
}
