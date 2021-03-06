#include "mercury.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "samurai ekars","武士 安卡斯" );
	add( "id", ({ "samurai","ekars" }) );
	set_short( "武士 安卡斯" );
	set_long(@AAA
在你面前是一位身高将近有三公尺的巨汉，由於安卡斯天生体格异於常人，所
以他所用的武器也和人不一样，不同於平常武士，反而使用重型的兵器，而因
为他天生神力,重型武器在他手上就和普通人的玩具一样
AAA
       );
	set( "unit", "位" );
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat( "str", 30 );
	set_perm_stat( "int", 13 );
        set_perm_stat( "dex", 15 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "pie", 15 );    
        set( "max_hp",700 );
        set( "hit_points",700 );
 	set_natural_armor( 60,22 );
	set( "natural_weapon_class1", 30 );
	set( "natural_min_damage1", 20 );
	set( "natural_max_damage1", 35 ); 
        set( "special_defense",([ "all":5,"none":15 ])); 
        set( "aim_difficulty",([ "critical":40,"weakest":10,"ganglion":5,
                                 "vascular":15 ]));
        set( "stun_difficulty/ma",13);  
	set( "alignment", 100 );
	set_c_limbs( ({ "头部", "身体", "手腕", "咽喉" }) );
        set_skill( "parry",40 );
        set_skill( "thrusting",100 );
        set_skill( "tactic",100 );
        set("tactic","berserk");
        set( "wealth" , ([ "silver": 400 ]) );    
        wield_weapon(MOBJ"cross_lance.c");
        equip_armor(MOBJ"black_vest.c");
        equip_armor(MOBJ"black_gauntlets.c");
        equip_armor(MOBJ"samurai_helm.c"); 
}
