#include "/d/eastland/beggar/dony.h"
#include <daemons.h>
#define C_NAME(x)     (string)x->query("c_name") 
#define NAME(x)       lower_case((string)x->query("name"))        
inherit MONSTER;

void create()
{
    ::create();
    set_level(19);
    set_name( "Mr. soothsayer", "神算小瓜" );
    add( "id",({"soothsayer"}) );
    set_short( "江湖术士 神算小瓜");
    set_long(@LONG
神算小瓜看起来约莫四、五十岁年纪,他过目不忘更生得一对天眼通。他生平钻研
卜筮之学,可谓上通天文下通地理, 凡是什麽易经之类的对他而言简直是小儿科。
他铁口直断,鲜有失误,所以很多人来求他开一金口但往往无功而返,因为他总是推
说无缘。他最近醉心於阵法之学,如果你能投他所好, 说不定他帮你算一段你就获
益非浅。神算小瓜也喜欢热闹的地方,一听到丐帮有个祭祖大典就跑来, 不知道他
是不是别有企图。
LONG
            );
    set("unit","位");
    set("race","human");      
    set("class","scholar");
    set("age",47);
    set("gender","male" );
    set("alignment",0);
    set("weight",700);
    set("wealth/gold",10);
    set("exp_reward",1) ;           
    set_temp("be_joke",10);
    set_perm_stat("str",20);
    set_perm_stat("dex",30);
    set_perm_stat("kar",30);
    set_perm_stat("int",30);
    set_perm_stat("pie",17);
    set("max_hp",1400);
    set("hit_points",1400);
    set("max_sp",1000);
    set("spell_points",1000);
    set("max_fp",1000);
    set("force_points",1000);
    set_natural_armor(86,38);
    set_natural_weapon(31,7,1);
    set_skill("shortblade",100);
    set_skill("dodge",70);
    set_skill("parry",75);
    set("couple",1);
    set("unbleeding",1);
    set("stun_difficulty",90);
    set("tactic","berserk");
    set("scholar_gonfu/mar_short",30);
    set("attack_skill","scholar/mar_short");
    command("party form");
    set("special_defense", ([ "all": 85,"none":85,"monk":40,"scholar":40]) );
    set("stun_difficulty",45);                                              
    equip_armor(DARMOR"soothsayer_cloth");
    set("embattle",
          ([ "four" : 1, "three" : 1, "two" : 1 ]));
    set("aim_difficulty",
     (["critical":45,"vascular":50,"ganglion":70,"weakest":30]) );
    set( "tactic_func", "my_tactic" );
}        
int accept_item(object me,object item)
{
    tell_room( environment(this_object()),
       "神算小瓜是不为利诱的。\n");
    item->remove() ;
    return 1;
}
int can_help( object ob )
{
   if( ob->query_attacker() ) return 0;
   if( ob->query("couple")) return 1;
       return 0;
}
void make_angry(object obj)
{
   object ob1,ob2,ob3,*all,env;        
        
    env=environment(obj);
    obj->set("hit_points",(int)obj->query("max_hp"));
    tell_room(env,C_NAME(obj)+
      "口里念念有词:「神恩如海天威如岳系系矩忙罗......」\n"+
      C_NAME(obj)+"大喝一声从背後飞出四口飞剑,顺势跃起抓起一柄 !!\n\n\n\n");
    obj->wield_weapon(DWEAPON"god_killed_sword4");
    obj->set("exp_reward",35735) ;
    obj->set("wealth/gold",800);
    ob1=new(DMONSTER"kill1");
    ob1->move(env);
    ob2=new(DMONSTER"kill2");
    ob2->move(env);
    ob3=new(DMONSTER"kill3");
    ob3->move(env);
    ob1->set("master",obj);
    ob2->set("master",obj);
    ob3->set("master",obj);
    ob1->set_temp("leader",obj);
    ob2->set_temp("leader",obj);
    ob3->set_temp("leader",obj);
    ob1->add_temp( "protectees", ({ obj }) );
    ob2->add_temp( "protectees", ({ obj }) );
    ob3->add_temp( "protectees", ({ obj }) );
    all=obj->query_temp("party_members");
    all=all+({ob1,ob2,ob3});
    obj->set_temp("party_members",all);
    obj->add_temp( "protectors",({ob1,ob2,ob3}));
    obj->set_temp("summon",1);
}

int my_tactic()
{
     object *all,*couples,victim,ob1,ob2,ob3;
     int i,members;     
     string name;
     
     if (!(victim= query_attacker())) return 0;
     name=lower_case(NAME(victim));
     couples = filter_array( all_inventory(environment(this_object())),
        "can_help", this_object() );
     for( i=0; i<sizeof(couples); i++ ) 
            couples[i]->kill_ob(victim);
     if ( this_object()->query("spell_points")<200) 
          this_object()->set("spell_points",1000);
     if ( this_object()->query("force_points")<200 )
          this_object()->set("force_points",1000);
     if (!this_object()->query_temp("summon")){
        make_angry(this_object());
     }
     if (!query_temp("embattle_busy")){
     switch( sizeof((mixed *)this_object()->query_temp("party_members"))){
     case 2:
               tell_room(environment(this_object()),
                  C_NAME(this_object())+"眼见势力孤单,於是施展两仪微尘阵\n");
               command("embattle two at "+name); 
            return 0;
     case 3:
               tell_room(environment(this_object()),
                  C_NAME(this_object())+"喝道:「看天地人三才阵」!\n");
               command("embattle three at "+name);
            return 0;
     case 4:
               tell_room(environment(this_object()),
                  C_NAME(this_object())+"施展四象璇玑阵\n");
               command("embattle four at "+name);  
            return 0;
     default :
            return 0;
     }
    }
    if ( victim->query("npc") ) {
        tell_room( environment(this_object()),
           this_object()->query("c_name")+"招来一道闪电把"
           +victim->query("c_name")+"化为灰尽....\n");
           victim->remove();
    }
    return 0;
}
void die()
{
    present("party_token",this_object())->remove();
    delete_embattle_effect(this_object());
    ::die(1);
}                  