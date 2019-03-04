#include "../story.h"
inherit MONSTER;

void create()
{
    ::create();
    set_level(16);
    set_name( "old fisher", "�ϵ���" );
    add ("id", ({ "fisher" }) );
    set_short( "�ϵ���");
    set_long(@LONG
����ǰ������һλ�����ٵ����ˣ�ͷ����һ����ñ��������һ�����£�����˫��
���ֳ���һ���ĳ߳��ĵ��ˣ��������Ե���¨�Լ�Щ�����֮�⣬�����������
ϸһ�����㻹�����������ߵ��ֱ��ƺ��������ƵĶ����������µ��ڸ��·���΢΢
�����⡣�ϵ����۾�������գ�̬�ȴ������ţ�������Ͼ������������ǰͷ������
���飬�ݹ��������ֻ���ۡ�����������Ǹ��ǳ��ˡ�
LONG
            );
    set("unit","λ");
    set("race","human");      
    set("age",70);
    set("gender","male" );
    set("alignment",500);
    set("weight",1000);
    set_perm_stat("str",30);
    set_perm_stat("int",25);
    set("hit_points",550);
    set("max_hp",550);
    set("max_fp",200);
    set_natural_armor(70,25);
    set_natural_weapon(15,10,20);
    set("tactic","assault");
    set_skill("blunt",60);
    set_skill("dodge",70);
    set_skill("parry",70);
    set("special_defense", ([ "all": 30,"none":30]) );
    wield_weapon(SWEA"fisher_staff");
    equip_armor(SARM"fisher_armband");
    set( "tactic_func", "my_tactic" );
    set("chat_chance",1);
    set("chat_output",({
       "�ϵ���������ص����������ȥ(how_to_out)��?\n"
    }) );
    set("inquiry", ([
       "how_to_out":"@@ask_help",
      "ghost_spell":"@@ask_spell"
    ]) );
}
void ask_spell(object asker)
{
   int i,max;
   object spell,*eq;
   if ( !asker->query_temp("wizelder") ) {
      tell_room(environment(),"�ϵ���˵�����Ҳ�֪����\n");
      return ;
   }
   spell=new(SWITEM"spell1");
   spell->move(environment());
   write(@LONG
   
�ϵ���˵���������Ҿ��������ʦ��������ǰ��Ϊ������۳ͷ�����������
            һֱ��������ܷ����춼��ȴ�������ڡ����� �ȳ��������
            ���ڸ���˵������������ǰ��һ��ʯͷ��ɵ�����ϣ����Ӣ��
            ���㣬����˳�������ȳ�.........


�ϵ���˵��֮��������һ�š���ħ�����ͱ��һ��ʯͷ����Ϫ��ȥ�ˡ�

����   
LONG
   );   
   asker->delete_temp("wizelder");
   this_object()->move("/u/d/dony/home/workroom");
   eq=all_inventory(this_object());
   max=sizeof(eq);
   for ( i=0;i<max;i++ )
     eq[i]->remove();  
   this_object()->remove();
}
void ask_help(object asker)
{
   write(@LONG
�ϵ���˵��������ǰ����һλ��ʦ���С�����С�ϡ������̫����ɥ����
���������������Ϫ�ȣ��ص��ڴ�ʩ�����������ղű�һ��ͻ������
�������������ķ紵���Ǿ�������֮һ�����������������ǽ�������
����������������纣��������ϵϵ��æ�ޡ�����Ҳ��̫����������ȥ
            �������˰ɡ�

�ϵ���˵���������㡣

LONG
   );
}
int my_tactic()
{
     object victim;
     
     if (!(victim= query_attacker())) return 0;
     if ( random(30)>8) return 0;
     victim->receive_damage(15+random(10));
     tell_room(environment(this_object()),
           "\n\n�ϵ��߰ѵ���ת��һ����Բ�������糤������һ�������ɨȥ��\n\n");
     return 1;
}                  