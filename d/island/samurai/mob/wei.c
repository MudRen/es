#include "mercury.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(17);
	set_name( "samurai wei","武士 威" );
	add( "id", ({ "samurai","wei" }) );
	set_short( "武士 威" );
	set_long(@AAA
威是一个年纪很轻的武士,虽然他年纪轻,但由於他天生对剑术有特别敏锐的
的感觉,所以已是武士团中年轻一代的佼佼者了,是次期队长的热门人选!!
AAA
          );
	set( "unit", "位" );
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat( "str", 25 );
	set_perm_stat( "int", 20 );
        set_perm_stat( "dex", 22 );
        set_perm_stat( "kar", 15 );
        set_perm_stat( "pie", 13 );    
        set( "max_hp",450 );
        set( "hit_points",450 );
 	set_natural_armor( 60,35 );
	set( "natural_weapon_class1", 30 );
	set( "natural_min_damage1", 20 );
	set( "natural_max_damage1", 35 ); 
        set( "special_defense",([ "all":25,"none":15 ])); 
        set( "aim_difficulty",([ "critical":90,"weakest":30,"ganglion":40,
                                 "vascular":5 ]));
        set( "stun_difficulty/ma",5);  
	set( "alignment", -100 );
	set_c_limbs( ({ "头部", "身体", "手腕", "咽喉" }) );
        set_skill( "parry",100 );
        set_skill( "longblade",70 );
        set_skill( "tactic",100);
        set("tacitc","berserk");
        set( "wealth" , ([ "gold": 30 ]) );
        set( "weight", 400 );    
        wield_weapon(MOBJ"dragonscale_sword.c");
        equip_armor(MOBJ"samurai_boots.c");
        equip_armor(MOBJ"samurai_leggings");
        equip_armor(MOBJ"heart_necklace.c");
         
}
