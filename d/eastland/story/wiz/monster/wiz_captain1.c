#include "../../story.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "The captain of Wizard bodyguard", "皇宫禁军队长" );
	add( "id", ({ "bodyguard","captain","guard" }) );
	set_short( "皇宫禁军队长" );
	set_long(@C_LONG
这是「巫咸城」皇宫禁军队长，不时领导禁卫军负责皇宫的安全，责任重大。禁军
队长从小就被城主收留教以十八般武艺，不但允文允武，报效城主更是因忠心耿耿
，贞坚不二，也因此倍受城主器重。他现在正在巡视皇宫安全，表情显的格外慎重
。
C_LONG
        );
	set( "gender", "male" );
	set( "alignment", 500 );
        set( "wealth/gold",100);
        set_perm_stat( "str", 28 );
        set_perm_stat( "dex", 15 );
        set_perm_stat( "int", 25 );
        set_perm_stat( "kar", 25 );
        set_skill( "parry", 90 );
        set_skill( "polearm", 90 );
        set_skill( "block", 90 );
        set("max_hp", 750);
        set("hit_points",750);
        set("max_fp", 350);
        set_temp("be_joke",100);
        set_temp("bs",100);
        set("special_defense", ([ "all":50, "none":35]) );
        set("aim_difficulty",
          (["critical":60,"vascular":60,"ganglion":60,"weakest":60]) );
        set("stun_difficulty",90);
        set_natural_armor(80,24);
        set_natural_weapon(13,11,7);
        set("bodyguard",1);
        set("tactic","assault");
        wield_weapon(SWWEA"polearm2");
        equip_armor(SWARM"wiz_shield2");
        set("tactic_func","my_tactic");  
        set("inquiry",([
           "killer":"@@ask_killer",
        ]) );
        set("chat_chance",1);
        set("chat_output",({
            "队长喃喃自语道：真不知道那天的刺客(killer)会躲到那里？\n"
        }) );
}
void ask_killer(object asker)
{
   write(@LONG
队长说道：那天宫里来了一个刺客，虽然失窃了一些东西，所幸没人伤亡。
　　　　　不过後来几次的拘补都被他逃逸了，真不知道他现在会躲在那里
　　　　　？ 　　
LONG
   );   
}
int can_help( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("bodyguard") ) return 1;
        return 0;
}
int my_tactic()
{
    object *couples,victim;
    int i,max;
                     
    if( !victim=query_attacker() ) return 0;
                        
    couples = filter_array( all_inventory(environment(this_object())),
              "can_help", this_object() );
    max = sizeof(couples);
    for( i=0; i<sizeof(couples); i++ ) {
        tell_room( environment(this_object()), sprintf(
           "%s大喊道：有人上门找碴了，大家快保护皇宫的安全。\n"
           ,couples[i]->query("c_name")));
        couples[i]->kill_ob(victim);
    }
    return 0;
}
