#include <mudlib.h>
#include <stats.h>
#include <conditions.h>
#include "../magic.c"

inherit MONSTER;

void create()
{
  ::create();
  set_level(16);
  set_name("flower centipede", "��ʰ�쵵ľ��ͻ����");
  add( "id", ({ "centipede" }) );
  set_short("��ʰ�쵵ľ��ͻ����");
  set_long(@LONG
һֻ�����ɳ��ľ�����򼡣Ҫ�������������İ��㣬��ֱ��һ������û��������
��ʰ�쵵ļ׿ǣ�ʮ����͸�������飬���л�ҧ��һֻɽ��ɽ��ȫ���ڣ�����
��Ƥ�ѳɰ�͸��״��������ֻ�����о綾��
LONG
    );
  set( "race", "insect" );
  set( "unit", "ֻ" );
  set( "alignment", -1200 );
  set_natural_armor( 40, 10 );
  set( "max_hp", 300 );
  set( "hit_points", 300 );
  set_skill("dodge",100);
  set_perm_stat( "str", 22 );
  set_perm_stat( "int", 20 );
  set_perm_stat( "dex", 25 );
  set_perm_stat( "kar", 27 );
  set_natural_weapon(50,25,25);
  set("aim_difficulty",(["critical":90,"weakest":50,"ganglion":100]));
  set("special_defense",(["all":30,"none":20]));
  set( "killer", 1 );
  set( "time_to_heal", 20 );
  set( "tactic_func", "emit_poison" );
  set_c_limbs( ({ "ͷ��", "����", "����", "β��" }) );
  set_c_verbs( ({ "%s��%s���һ�ں���" ,
                  "%s��β��һ����ס��%s",
                  "%s�������Ŀ��ҧ��%s"
                  }) );
}

int emit_poison()
{
  object victim;

  if( random(20)>10 || !(victim= query_attacker()) ) return 0;
  tell_object( victim,sprintf(
    "\n��ѽ����⣡�㱻��������µ�%s������......\n",set_color("����","CYN"))
    );
  (CONDITION_PREFIX + "simple_poison")->apply_effect( victim,5, 20 );
  victim->receive_special_damage("poison",30);  
  report(this_object(),victim);
  return 1;
}
void die()
{
     object killer;
     if ( killer=query("last_attacker") ) killer->add_temp("mobs",3);
     ::die();
}