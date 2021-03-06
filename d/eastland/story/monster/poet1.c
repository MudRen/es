#include "../story.h"
inherit MONSTER;

void create()
{
    ::create();
    set_level(16);
    set_name( "poet","吟游诗人" );
    add ("id", ({ "poet" }) );
    set_short( "吟游诗人");
    set_long(@LONG
一位清瘦逸隽风度翩翩的吟游诗人，他正偕伴四处观山阅岭游玩探访故人，路过此
地见风景尚好，遂来此凉亭稍微小憩一番，又爱亭旁莲池莲花之清丽，因景因物因
时因地，因此兴起吟诗作对之念。
LONG
            );
    set("unit","位");
    set("race","human");      
    set("age",30);
    set("gender","male" );
    set("alignment",100);
    set("weight",1000);
    set("max_fp",200);
    set("wealth/silver",200);
    set_perm_stat("str",23);
    set_natural_armor(75,5);
    set_natural_weapon(28,14,30);
    set_skill("unarmed-parry",50);
    set_skill("dodge",80);
    set_skill("unarmed",70);
    set("special_defense", ([ "all": 20,"none":20]) );
    set("stun_difficulty",30);
    set("couples",1);
    set( "tactic_func", "my_tactic" );
    set("chat_chance",1);
    set("chat_output",({
       "吟游诗人闲谈道：不知道被芭蕉扇乱刮是什麽滋味。\n"
    }) );
}        
int can_help( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("couples") ) return 1;
        return 0;
}
int my_tactic()
{
    object *couples,victim;
    int i,max;
                        
    if( !victim=query_attacker() ) return 0;
                            
    couples = filter_array( all_inventory(environment(this_object())),
          "can_help", this_object() );
    max=sizeof(couples);
    for( i=0; i<max; i++ ) {
       tell_room( environment(this_object()), sprintf(
          "%s怒道：哼，你以为我们是易与之辈吗？你莫要打错了算盘。\n"
          ,couples[i]->query("c_name")));
       couples[i]->kill_ob(victim);
    }
    return 0;
}