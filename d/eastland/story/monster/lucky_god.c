#include "../story.h"
inherit MONSTER;
int receive_damage(int damage);
void create()
{
    ::create();
    set_level(17);
    set_name( "lucky god", "̩��" );
    add ("id", ({ "god" }) );
    set_short( "���� ̩��");
    set_long(@LONG
̩�곤��һ���˵����Ӷ�����������һ�������Ŀ״���ë�������������Χ��ʱ��
���������Ĺ���������ǡ����������һ����׹⣬����һ�֡�����ֹֹ���Ŀɰ�
��â��Ҳ���������й����������ϣ��֮�⡣��˵��̩���������н������ã���
�������Ǿͱ�ʾ���Ҫ��ϲ�������ˣ�̩��������׼��Ҫ����̫ɽɽ������Ⱦƣ�
��������һ�����«��
LONG
            );
    set("unit","λ");
    set("race","god");      
    set("age",59);
    set("gender","male" );
    set("weight",1000);
    set("wealth/gold",100);
    set_temp("be_joke",100);
    set_temp("bs",10000);
    set_perm_stat("str",22);
    set_perm_stat("dex",25);
    set_perm_stat("kar",30);
    set_perm_stat("int",30);
    set("hit_points",500);
    set("max_hp",500);
    set("max_fp",250);
    set_natural_armor(1,100);
    set_natural_weapon(300,15,9);
    set_skill("dodge",100);
    equip_armor(SARM"lucky_cloth");
    set( "tactic_func", "my_tactic" );
}        
int receive_damage(int damage)
{
   if ( damage > 40 ) damage=40;
   ::receive_damage(damage);
}
int my_tactic()
{
     object victim,env,*atk;
     int select;     
     
     if (!(victim= query_attacker())) return 0;
     if (random(8)>6) return 0;
     env=environment(this_object());
     tell_room(env,"̩��ŭ����������С���Ҵ����д�����������ƽ��ˡ�\n");
     atk=env->query("exit");
     select=random(sizeof(atk));
     command(sprintf("go %s",atk[select]));
     return 0;          
} 
void die()
{
   object card,gourd;
   gourd=new(SITEM"gourd1");
   gourd->move(environment());
   card=new(SITEM"card1");
   card->move(environment());
   tell_room(environment(),"��̩��ı������һ����«��һ��ֽ��\n");
   ::die();
}                 