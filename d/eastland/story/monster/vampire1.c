#include "../story.h"
#include <stats.h>
#include <conditions.h>
#include "../magic.c"
inherit MONSTER;
int delay=6;
int duration=10;
int damage=8;
void create()
{
    ::create();
    set_level(19);
    set_name( "The great vampire", "���� �ȳ�" );
    add ("id", ({ "vampire" }) );
    set_short( "�������� �ȳ�");
    set_long(@LONG
�����ȳ����ĸ���ųߣ�˫�ֹ�ϥ��һ��׹�Ҳ�Ƶ��������ĩ��֮�⣬ҵ������
��Щ��Ƥ�⣻һ������۾����ںڰ������Ʋ��ѣ����������ɫ�Ĺ�â����Ҫ����
��Ļ��ǣ��ǽţ����ƶ��˰��Ӳ��������Ƶģ�һ���㣬ȴ�ƻ������������߳�
�߷ɳ�����Զ�������ȳ�������ҡͷ���Ե������ƣ�����������������ǰ�ˣ�����
��Ѫ����������֣���������������ģ�
LONG
            );
    set("unit","λ");
    set("age",100);
    set("killer",1);
    set("pursuing",1);
    set("alignment",-2500);
    set("weight",1000);
    set_perm_stat("str",30);
    set_perm_stat("dex",30);
    set_perm_stat("kar",30);
    set_perm_stat("int",30);
    set("hit_points",5000);
    set("max_hp",5000);
    set("max_fp",600);
    set_natural_armor(100,35);
    set_natural_weapon(80,40,60);
    set_skill("dodge",100);
    set_skill("unarmed",100);
    set("special_defense", ([ "all": 80,"none":30]) );
    set("aim_difficulty",
    (["critical":50,"vascular":50,"ganglion":50]) );
    set("stun_difficulty",100);
    set_c_verbs( ({
        "%s�ſ�����Ѫ���ڣ�һ����%sҧȥ",
        "%s�Ӷ�������צ����%sץȥ"}) );
    set_c_limbs( ({ "ͷ��", "����", "�Ų�", "˫��" }) );
    equip_armor(SARM"vampire_amulet");
    set( "tactic_func", "my_tactic" );
}        
int my_tactic()
{
     object *victim,env;
     int i,max;     
     
     if (!victim=query_attackers()) return 0;
     env=environment(this_object());
     if (!query("be_hurt") && env->query("trap_set")) {
     set("be_hurt",1);
     tell_room(env,@LONG

ֻ������������һ�����ɹ�âֱ͸���϶�ȥ����Ȼ��



���� �ȳ���һ������ļ��������
ԭ�����ϵķ���ҵ�ѷ������ã������� �ȳ����ܵ��ش�����



LONG     
     );
     set_perm_stat("str",25);
     set_perm_stat("dex",20);
     set_perm_stat("kar",20);
     set_perm_stat("int",20);
     set("hit_points",1000);
     set_natural_armor(70,25);
     set_natural_weapon(70,30,50);
     delay=4;
     duration=5;
     damage=5;
     }
     max=sizeof(victim);
     switch( random(40) ) {    
     case 0..1 :
        tell_room(env,set_color(
           "\n\n���� �ȳ�  �³�һ����ɫ�Ļ���������������䣡\n\n","HIG"));          
        for (i=0;i<max;i++)
          (CONDITION_PREFIX + "simple_poison")->apply_effect(victim[i],duration,damage);
        break;
     case 2..4 :
        tell_room(env,set_color(
           "���� �ȳ� ͻ����������צ���ѵ��˺ݺ�ץ�Σ�\n","HIW"));
        for (i=0;i<max;i++){
           victim[i]->block_attack(delay);
           victim[i]->set_temp("msg_stop_attack",
             "(  �㱻���� �ȳ�ץס����������ã�  )\n");
        }
        break;
     case 5..6 :
        tell_room(env,set_color(
           "\n���� �ȳ� ������������˵ľ���ҧȥ���������ڶ�����Ѫ��\n\n\n","HIR"));
        for (i=0;i<max;i++) 
           (CONDITION_PREFIX + "bleeding")->apply_effect(victim[i],duration,damage );
        break;
     default:
        break;                                  
     }
     return 0;          
}
void die()
{
    object ball,killer;
    string name;
    SAREA"vhole1"->set("have_vampire",0);
    SAREA"vhole2"->set("have_vampire",0);
    SAREA"vhole3"->set("have_vampire",0);
    SAREA"vhole1"->set("trap_set",0);
    SAREA"vhole2"->set("trap_set",0);
    SAREA"vhole3"->set("trap_set",0);
    tell_room(environment(),"�ȳ�����ǰ�Ӷ��������һ����ɫ�����ӡ�\n");
    killer=query("last_attacker");
    if ( killer ) {
       if (!(name=killer->query("org_name"))) 
          name=killer->query("name");
    } else name="????";
    ball=new(SITEM"ball1");
    ball->set("master",name);
    ball->move(environment());
    ::die();
}                  