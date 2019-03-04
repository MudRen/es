#include <mudlib.h>
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(13);
       set_name("wild insect","�ȴ�����" );
       add("id",({"insect"}) );
       set_short( "�ȴ�����" );
       set("unit","ֻ");
       set_long(@LONG
һֻ���ι�״�����棻��ǰ������������һ��ī��ɫ��Сͷ��ͷ�ϵ�С�۹�����
�����������ƣ�������ʲ����ͼ��������������ȴ�������ϵĴ������ж�ʮ����
�������������ԣ�������Գ�������֫����֫����ë���޵���ë���ɲ����ˣ���
����һ��Ӻ�׵�ģ�����ж�����ȴѸ���Ѽ�������������ʲ�ᶯ���ѽ������
���㹥����
LONG
       );
       set("killer",1);
       set("hit_points",80);
       set_perm_stat("str",20);
       set_natural_armor(65,0);
       set_natural_weapon(18,12,21);
       set_c_verbs(({"%s������ǰ��֫��%s����",
                     "%s��������֫�ݺ���%sһ��",
                     "%s������ͷ��ײ��%s"
       }));
       set_c_limbs(({"����","ͷ��","��֫"}));
}
void kill_reward(object killer)
{
   switch( random(3) ) {
   case 0: killer->add("hit_points",-100);
           break;
   case 1: killer->add("force_points",-150);
           break;
   default: killer->add("spell_points",-150);
           break;    
   }
   ::kill_reward(killer);
}
void die()
{
   tell_room(environment(this_object()),
      "��ѽ���ȴ�����������ͳ�һ�����򣬺�Ȼ�������Ƶ���������һ����ɫҺ�壡��\n\n");
   set("alt_corpse","NONE");
   ::die(1);
}
