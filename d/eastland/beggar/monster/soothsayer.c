#include "/d/eastland/beggar/dony.h"
#include <daemons.h>
#define C_NAME(x)     (string)x->query("c_name") 
#define NAME(x)       lower_case((string)x->query("name"))        
inherit MONSTER;

void create()
{
    ::create();
    set_level(19);
    set_name( "Mr. soothsayer", "����С��" );
    add( "id",({"soothsayer"}) );
    set_short( "������ʿ ����С��");
    set_long(@LONG
����С�Ͽ�����ԼĪ�ġ���ʮ�����,����Ŀ����������һ������ͨ������ƽ����
����֮ѧ,��ν��ͨ������ͨ����, ����ʲ���׾�֮��Ķ������Լ�ֱ��С���ơ�
������ֱ��,����ʧ��,���Ժܶ�����������һ��ڵ������޹�����,��Ϊ��������
˵��Ե��������������֮ѧ,�������Ͷ������, ˵������������һ����ͻ�
���ǳ������С��Ҳϲ�����ֵĵط�,һ����ؤ���и������������, ��֪����
�ǲ��Ǳ�����ͼ��
LONG
            );
    set("unit","λ");
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
       "����С���ǲ�Ϊ���յġ�\n");
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
      "���������д�:������纣��������ϵϵ��æ��......��\n"+
      C_NAME(obj)+"���һ���ӱ���ɳ��Ŀڷɽ�,˳��Ծ��ץ��һ�� !!\n\n\n\n");
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
                  C_NAME(this_object())+"�ۼ������µ�,���ʩչ����΢����\n");
               command("embattle two at "+name); 
            return 0;
     case 3:
               tell_room(environment(this_object()),
                  C_NAME(this_object())+"�ȵ�:���������������!\n");
               command("embattle three at "+name);
            return 0;
     case 4:
               tell_room(environment(this_object()),
                  C_NAME(this_object())+"ʩչ���������\n");
               command("embattle four at "+name);  
            return 0;
     default :
            return 0;
     }
    }
    if ( victim->query("npc") ) {
        tell_room( environment(this_object()),
           this_object()->query("c_name")+"����һ�������"
           +victim->query("c_name")+"��Ϊ�Ҿ�....\n");
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