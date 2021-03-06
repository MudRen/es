#include <mudlib.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "poison spider", "文蛛" );
	add ("id", ({ "spider" }) );
	set_short( "文蛛" );
	set_long(@C_LONG
一只全身七彩斑斓的巨型蜘蛛，它全身毛绒绒的，更兼两只长长的利爪在你面前□
来□去的，恶心又可怖极了。相传，文蛛喜欢出没在人烟罕至的炎热地带，鲜有人
能躲过它的攻击，令不少人丧命在它的利爪之下。
C_LONG
	);
        set("killer",1);
        set( "alignment",-1000);
        set( "unit", "只" );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "str", 28 );
	set_perm_stat( "int", 10 );
	set_perm_stat( "karma", 30);
	set_skill("dodge",100);
	set("special_defense", (["sleet":-25,"none":60,"fire":100]) );
        set("aim_difficulty",([
           "critical":100,"ganglion":30 ]) );
	set("max_hp", 1000);
	set("hit_points", 1000);
	set("max_fp",500);
	set_natural_weapon(57,35,53);
	set_natural_armor(70,1);
        set ("weight", 1000);
        set_c_verbs( ({ "%s张著两只大牙，往%s咬下",
                        "%s用毛茸茸的前肢往%s一刺" }) );
        set_c_limbs( ({ "头部", "身体", "腿部" }) );
        set( "tactic_func", "my_tactic" );
}
int my_tactic()
{
    object victim;
    if ( !victim=query_attacker() ) return 0;
    if ( random(15) > 2 ) return 0;
    tell_room(environment(this_object()),sprintf(
      "文蛛吐出长长的蛛丝捆住%s！\n",victim->query("c_name")),victim);  
    tell_object(victim,
      "\n文蛛吐出长长的蛛丝向你身上一捆，令你难受已极！！\n\n");
    (CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 5 , 5 );
    victim->block_attack(4);
    victim->set_temp("msg_stop_attack",
        "(  你被捆住了，动弹不得！！  )\n");
    return 0;
}