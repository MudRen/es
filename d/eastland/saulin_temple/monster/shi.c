#include "../saulin_temple.h"

inherit MONSTER;

void create ()
{
	::create();
	seteuid( getuid() );
	set_level(17);
	set_name("master shi hun","般若堂首座 虚行");
	add("id",({"shi","hun","monk","master"}) );
	set_short("般若堂首座 虚行");
	set_long(@C_LONG
般若堂专门研究各门各派的武学绝技，使得少林子弟将来遇到对手时得以
知己知彼百战百胜... 所以般若堂首座必然精通江湖各门各派武艺... 虚
行是个九十岁的老僧，他八岁入少林，自幼嗜武成痴，尤擅内劲及指力，
人称「白发佛」。他对江湖各门各派武学莫不了如指掌，加上七十年的易
经筋火侯，武艺可说是炉火纯青。
C_LONG
	);
	set( "alignment", 1300 );
	set( "gender", "male" );
	set( "race", "human");
	set( "unit", "位" );
	set_perm_stat( "dex",27);
	set_perm_stat( "str",28);
	set_perm_stat( "int",23);
	set("max_hp", 800);
	set("hit_points", 800);
	set("max_fp", 4150);
	set("force_points", 4150);
	set("wealth/gold", 70 );
	set_natural_weapon( 10, 9, 9 );
	set_natural_armor( 50, 12 );
	set("special_defense", ([ "all" : 60, "none" : 48 ]) );
	set("aim_difficulty",([ "critical" : 56, "vascular" : 60 ]) );
	set("weight", 840);
	wield_weapon( SAULIN_OBJ"thu" );
	equip_armor( SAULIN_OBJ"cloth2" );
	equip_armor( SAULIN_OBJ"glove1" ); 
	equip_armor( SAULIN_OBJ"necklace2" );
	equip_armor( SAULIN_OBJ"armband2" ); 
 set("special_attack",(["damage_type" : "mental","main_damage" : 40,
                                "random_dam" : 20 , "hit_rate" : 25]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg",
"\n虚行无奈的说：施主如此行为，莫怪老僧无礼了!!!\n\n"+
"但见虚行双手合十，双脚深陷入青石地板中，突然一声断喝，使出少林七十二\n"+
"绝技『一指禅』... 他身形一变，手中打出一股强烈的真气，你只感到一股巨\n"+
"力如洪水□堤般冲来... 。\n\n" );
set("c_room_msg","\n虚行无奈的说：施主如此行为，莫怪老僧无礼了!!!\n\n"+
"但见虚行双手合十，双脚深陷入青石地板中，突然大喝一声，使出少林七十二\n"+
"绝技『一指禅』... 他身形一变，手中打出一股强烈的真气，射向");
set("c_room_msg2", "的身体 ...\n");
}

