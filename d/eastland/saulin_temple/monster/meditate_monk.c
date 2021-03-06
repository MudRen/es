#include "saulin_monka.c"

void create()
{
	::create();
	set_level(8);
	set_name( "Meditate monk", "沈思的和尚" );
	add ("id", ({ "monk", }) );
	set_short( "沈思的和尚" );
	set_long(
    	"一个安静的和尚，他正不知道在想些什麽？\n"
    );
	set("alignment", 100);
	set("gender", "male");
	set("race", "human");
	set("unit", "个");
	set_perm_stat("str", 12);
	set_perm_stat("int", 15);
	set_perm_stat("dex", 16);
	set("wealth/gold", 5);
	set("max_fp", 500);
	set("force_points", 500);
	set("force_effect",2);
	set_natural_weapon( 14, 8, 13 );
	set_natural_armor( 40, 13 );
	set("sepcial_defense", ([ "all" : 10, "none" : 3, ]) );
	set("aim_defficulty", ([ "critical" : 10 ]) );
	set("weight", 300);
	set_skill("unarmed",60);
	set_skill("dodge",80);
	set("defense_type","dodge");
	equip_armor( SAULIN_OBJ"pallium" );
}
