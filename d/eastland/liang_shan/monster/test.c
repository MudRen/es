#include "../takeda.h"
#include "/include/move.h"
#include <daemons.h>
#define C_NAME(x)     (string)x->query("c_name") 
#define NAME(x)       lower_case((string)x->query("name"))        
inherit MONSTER;

void create()
{
    ::create();
      set_level(17);
      set_name( "Zhu Wu", "朱武" );
      add ("id", ({ "zhu", "wu" }) );
      set_short( "朱武");
      set("unit","位");
      set("alignment",300);
      set("weight",400);
      set("wealth/platinum",8);
      set_long(
      "定远县人，外号神机军师，使一柄三尖两刃刀，武艺高强且精通阵法．\n"
      "为梁山泊一同参赞军务头领。\n"
      );
       set_perm_stat("dex", 25);
       set_perm_stat("str",18);
       set_perm_stat("kar",20);
       set("max_hp",440);
       set("hit_points",440);
       set("natural_defense_bonus",20);
       set ("natural_weapon_class1", 10);
       set ("natural_armor_class", 40);
       set ("special_defense",(["fire":50,"none":30]));
       set ("gender", "male");
       set_skill("longblade",70);
       set_skill("parry",80);
       set_skill("dodge",70);
            wield_weapon(TWEAPON"threeblade");
            equip_armor(TARMOR"brass_hat");
            equip_armor(TOBJ"flag");
            equip_armor("/d/eastland/goomay/obj/doshu_robe");
    set_temp("be_joke",10);
    set("class","scholar");
    set("max_sp",1000);
    set("spell_points",1000);
    set("max_fp",500);
    set("force_points",500);
    set("couple",1);
    set("stun_difficulty",40);
    set( "alt_corpse", "NONE" );
    set("tactic","flank");
    set("scholar_gonfu/song",40);
    set("attack_skill","scholar/song");
    set("embattle",
          ([ "four" : 1, "three" : 1, "two" : 1 ]));
    set( "tactic_func", "my_tactic" );
    set("inquiry",([
                "join" : "@@ask_join"
                  ]));
    command("party form");
}        
void init()
{
::init();
add_action("do_nod","nod");
}

int ask_join()
{
if ( this_player()->query_temp("ready_join") >2 ) {
command("look "+(string)this_player()->query("name"));
command("kick "+(string)this_player()->query("name"));
command("say "+"你已经通过甄试了，不要来耍宝好吗?");
return 1;
} 
command("look "+(string)this_player()->query("name"));
command("say "+"如果你想加入山贼，首先你要先证明你的能力。你准备好了吗?");
this_player()->set_temp("ready_join",1);
return 1;
}
int do_nod()
{
  if ( (int)this_player()->query_temp("ready_join") == 1 ) {
  write("你用力的点了点头\n");
  write("朱武说道: 好吧，只要能打败我就证明了你的能力...\n");
  this_object()->kill_ob(this_player());
  this_player()->set_temp("ready_join",2);
  return 1;
  }
  return 0;
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
        
    if( random(8) > 1 ) return ; 
    env=environment(obj);
    tell_room(env,C_NAME(obj)+
      "大喝:「弟兄们，又有人来给我们练阵法了....」\n"
      "一大群山贼不知从那儿跑了出来，把你团团围住... \n\n");
    set("party_num",4);
    command("party disband");
    command("party form");
    set_temp("embattle_busy",0);
    ob1=new(TMONSTER"power_bandit");
    ob1->move(env);
    ob2=new(TMONSTER"power_bandit");
    ob2->move(env);
    ob3=new(TMONSTER"power_bandit");
    ob3->move(env);
    ob1->set("master",obj);
    ob2->set("master",obj);
    ob3->set("master",obj);
    ob1->set_temp("leader",obj);
    ob2->set_temp("leader",obj);
    ob3->set_temp("leader",obj);
    ob1->set( "alt_corpse", "NONE" );
    ob2->set( "alt_corpse", "NONE" );
    ob3->set( "alt_corpse", "NONE" );
    ob1->add_temp( "protectees", ({ obj }) );
    ob2->add_temp( "protectees", ({ obj }) );
    ob3->add_temp( "protectees", ({ obj }) );
    all=obj->query_temp("party_members");
    all=all+({ob1,ob2,ob3});
    obj->set_temp("party_members",all);
    obj->add_temp( "protectors",({ob1,ob2,ob3}));
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
     if ( this_object()->query("spell_points")<200 ) 
          this_object()->set("spell_points",1000);
     if (!present("thief",environment(this_object()))){
        make_angry(this_object());
     }
     if (!query_temp("embattle_busy")){
     switch( query("party_num") ) {
     case 2:
               tell_room(environment(this_object()),
                  C_NAME(this_object())+"喝道:「结两仪微尘阵」!\n");
               command("embattle two at "+name); 
            return 0;
     case 3:
               tell_room(environment(this_object()),
                  C_NAME(this_object())+"喝道:「结天地人三才阵」!\n");
               command("embattle three at "+name);
            return 0;
     case 4:
               tell_room(environment(this_object()),
                  C_NAME(this_object())+"喝道:「结四象璇玑阵」!\n");
               command("embattle four at "+name);  
            return 0;
     default :
            return 0;
     }
    }
    return 0;
}
void die()
{
    object ob1,killer;
    killer = query("last_attacker");
    present("party_token",this_object())->remove();
//    delete_embattle_effect(this_object());
    if ( (int)killer->query_temp("ready_join") == 2 ) {
    killer->set_temp("ready_join",3);
    ob1 = new(TOBJ"ability_evidence");
    if( (int)(ob1->move(killer)) != MOVE_OK )
    ob1->move(environment(this_object()));
    ob1->set("owner",killer);
    tell_room(environment(this_object()),
        C_NAME(this_object())+"笑道:「恭喜你，你通过了资格的甄试，我开个证明给你吧」\n"
        "说完，朱武从怀中摸出一张纸片，交给"+killer->query("c_name")+"\n\n");
    tell_room(environment(this_object()),
        C_NAME(this_object())+"无奈地叹道:「你把我打成这样，我要去休息休息了....」\n");
    }
    else {
    tell_room(environment(this_object()),
    C_NAME(this_object())+"喝道:「快结阵」!\n\n\n");
    tell_room(environment(this_object()),
    C_NAME(this_object())+"叹道:「怎麽都跑光了? 三十六计，还是走为上策....」\n");
    }
    command("wave");
    command("drop all");
    ::die(1);
}
int stop_attack()
 {
   object bandit,*tmp;
   bandit = present("thief",environment());
       
       if (!bandit) return 0;
       tmp =query_temp("protectors");
       if(! tmp || member_array(this_player(),tmp)==-1);
       bandit->kill_ob(this_player());
 }                   