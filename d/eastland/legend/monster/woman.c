#include <mudlib.h>

inherit MONSTER;

void create()
{
  ::create();
  set_level(16);
  set_name("woman", "����ɣ");
  add( "id", ({ "woman" }) );
  set_short("����ɣ");
  set_long(@C_LONG
һλ������͵�����ɣ������ɣ������������ţ����ڵ��ھ��߱�ϴ�·��ߺ��Ա�
�ĸ������졣��춳����˵ص�����ԣ�������������Ǵ�����ʲ����ϢҲ˵������  
C_LONG  
    );
  set( "race", "human" );
  set( "unit", "��" );
  set( "gender", "female");
  set_natural_weapon(30,18,33);
  set_natural_armor( 70, 18 );
  set( "max_hp", 400 );
  set( "hit_points", 400 );
  set_perm_stat( "int", 17 );
  set_perm_stat( "str", 20 );
  set_perm_stat( "dex", 22 );
  set_perm_stat( "pie", 18 );
  set( "inquiry", ([
     "�峤":"@@ask_captain",
  ]) );
  set( "tactic_func", "my_attack" );
}
void ask_captain(object asker)
{
write(@C_LONG
����ɣ����ร��峤�ļҾ���ǰ�治Զ���İ����ӡ����������Ĵ峤����
C_LONG
     );
}
int my_attack()
{
  object victim;
  if( random(20)>7 || !(victim= query_attacker()) ) return 0;
  tell_object(victim,"����ɣ��������ϴ��ˢ��������һ��\n");
  tell_room(environment(this_object()),sprintf(
       "����ɣ��������ϴ��ˢ��%s����һ��\n",victim->query("c_name")),victim);
  victim->receive_damage(10);
  return 0;
}
