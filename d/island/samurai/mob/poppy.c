#include "mercury.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(16);
	set_name( "Ninjadog Poppy", "忍犬 巴比" );
	add( "id", ({ "ninjadog","dog","poppy" }) );
	set_short( "Ninjadog Poppy", "忍犬 巴比" );
	set_long(@AAA
这是一只凶猛的大狗，由於受过忍法的训练，有比一般警卫犬有更强的
战力，是加尔福特的爱犬！
AAA
 );
	set( "unit", "只" );
	set( "race", "monster" );
	set( "gender", "male" );
	set_perm_stat( "str", 25 );
        set_perm_stat( "dex", 25 );    
        set( "max_hp",350 );
        set( "hit_points",350 );
 	set_natural_armor( 60,25 );
	set( "natural_weapon_class1", 60 );
	set( "natural_min_damage1", 15 );
	set( "natural_max_damage1", 35 ); 
        set( "special_defense",([ "all":15,"none":15 ])); 
        set( "aim_difficulty",([ "critical":90,"weakest":15,"ganglion":50,
                                 "vascular":35 ]));
        set( "stun_difficulty/ma",15);  
	set( "alignment", 1000 );
	set_c_limbs( ({ "头部", "身体", "前脚", "咽喉","後腿","尾巴" }) );
        set_skill( "tactic",100 );
        set("tactic","berserk");
        set( "wealth" , ([ "silver": 70 ]) );
        set_c_verbs( ({"%s冲到你面前，用後脚对%s一阵乱踢","%s突然消失，从空中落下来撞%s",
                       "%s飞扑过来，用利爪抓向%s"}));    
}
