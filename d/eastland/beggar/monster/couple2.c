#include "../dony.h"

inherit MONSTER;

#include <stats.h>
#include <conditions.h>

void create()
{
	::create();
	set_level(15);
	set_name( "the younger of couples", "鹰老" );
	add("id",({"couple","couples","younger"}) );
        set_short( "天山二老 鹰老" );
	set_long(@C_LONG
天山二老在江湖上极具身份与地位, 十多年前一役击杀为害多时的『广东六虎』,
更而倍受武林人士所推祟。鹰老是天山二老中较年轻者, 看起来矮矮胖胖的,他的
双手尖而有力练得是一套大擒拿手法,被他擒住都是难逃九死一生。他偕著鹤老来
参加丐帮祭祖大典,顺便要向其它武林人士讨教一番。
C_LONG
	);
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", 50 );
	set( "time_to_heal", 7 );
	set_natural_armor( 35, 18 );
	set_natural_weapon( 40, 17 , 29);
	set("max_hp",500);
	set("hit_points",500);
	set("force_points",400);
	set_perm_stat( "str", 25 );
	set_perm_stat( "dex", 25 );
	set_skill( "parry",30 );
	set( "wealth/silver",150);
	set( "special_defense", ([ "all": 20 ]) );
	set( "aim_difficulty",(["critical":60,"vascular":30,"weakest":50]) );
	set("couple",1);
        set_c_verbs( ({ "%s使出『 大 悲 手 』第一式, 拍向%s要害",
                        "%s以退为进使出『 大 悲 手 』第二式, 双手舞成一个圆扑向%s",
                        "%s暴吼一声, 『 大 悲 手 』第三式向%s递了过来",
                        "%s猛地使出『 大 悲 手 』最强一式, 漫天人影向%s直攻而来"
                      }) ); 
        equip_armor(DARMOR"couple_cloak");
        set( "tactic_func", "my_attack" );
        set( "chat_chance", 20 );
        set( "att_chat_output", ({
                 "天山二老 鹰老狂笑道:又有一个找死,正好拿你来试试我的新掌法!! \n"
            }) );
} 

int can_help( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("couple") ) return 1;
        return 0;
}


int my_attack()
{ 
    object *couples,victim;
    int i;
    
    victim = query_attacker();
    if( !victim ) return 0;
    
    couples = filter_array( all_inventory(environment(this_object())),
           "can_help", this_object() );
    for( i=0; i<sizeof(couples); i++ ) {
        tell_room( environment(this_object()), couples[i]->query("c_name")+
            "怒道:我们岂是那麽好欺负的,给我下地狱去吧!!\n",couples[i]);
        couples[i]->kill_ob(victim);
    }

    if( random(20)>4 ) return 0;
    if( victim->query("stop_attack") ) return 0;
    
    tell_room( environment(this_object()),
              "\n\n鹰老施展『 大 擒 拿 手 』把"+
               victim->query("c_name")+"狠狠的抓住令他动弹不得!!\n",victim);
    tell_object( victim,"\n\n"+this_object()->query("c_name")+
              "施展『 大 擒 拿 手 』把你狠狠的抓住,令你动弹不得!!\n");
    victim->block_attack(10);
    victim->set_temp("msg_stop_attack","(  你被擒住了,动弹不得 !!  )\n");
    return 1;
}

