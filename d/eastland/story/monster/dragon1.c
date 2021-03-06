#include <mudlib.h>

inherit MONSTER ;

void create ()
{
	::create();
	set_level(18);
	set_name( "thunder dragon", "应龙" );
	add ("id", ({ "dragon"}) );
	set_short( "雷兽 应龙");
	set_long(@CLONG
应龙生著一对晶莹剔透的翅膀，原是住在「凶犁土邱山」的南端，善能畜水行
雨。应龙当年受黄帝大战蚩尤所托，前来助阵。因为那时蚩尤会作大雾，但黄帝心
想，应龙能下大雨，难道大雨远不及大雾？结果黄帝失算，因为蚩尤早已搬请了风
伯雨师来，风伯雨师祭起滔天雨水，使应龙犹如「小巫见大巫」般地而撤退。後来
蚩尤战败，黄帝勒命应龙看守这里，以防北边的解池有所变异。
CLONG
	);
	set_perm_stat("str", 25 );
        set_perm_stat("kar", 10 );
        set_perm_stat("int", 30 );
	set_skill( "dodge", 100 );
	set( "alignment", 800 );
	set( "hit_points", 800 );
	set( "max_hp", 800 );
        set( "max_fp",400);
	set_natural_weapon( 57, 23, 38 );
	set_natural_armor( 117, 20 );
        set( "tactic", "flank" );
        set("special_defense",(["all":30]));
        set("aim_difficulty",([ 
    	  "critical":80,"vascular":50,"weakest":50,"ganglion":50 ]) );
        set_skill("concentrate",100);
        set_skill("target",100);
        set_skill("black-magic",100);
        set("time_to_heal",5);
        set("spells/lightning",1);
        set("guild_levels/black-magic",50) ;
        set_c_limbs(({"身体","头部","脚部","手臂"}));
        set_c_verbs(({
                "%s用它的利爪向%s抓去",
                "%s伸出它那长满利牙的嘴巴向%s咬去"
        }));
        set("tactic_func","my_tactic");
}
int my_tactic()
{
    int i;
    object victim;
    if ( !victim=query_attacker() ) return 0;
    if ( random(14)> 3 ) return 0;
    if ( query_temp("cast_busy") ) return 0;
    for ( i=0;i<2;i++ ) 
       command("cast lightning on "+victim->query("name"));
    set("stop_attack",0);
    return 1;
}
