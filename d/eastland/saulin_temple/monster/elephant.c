#include "../saulin_temple.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "A huge elephant", "�����" );
	add( "id", ({ "elephant"}) );
	set_short( "�����" );
	set_long(@ELEPHANT
�㿴��һͷ���������ͷ�ϴ����ƽ�Ĵ��Σ����ϰ���һ���������Σ���Ӧ����
ĳλ��������ֻ���������ܰ��꣬���������ֻ������ó����Ĵ���Ӱ���
��Ҷ�ԣ��������ĳ���ʵ���й��ѿ������������İ����õ������ƻ���һ齺�Ϳ��
����øϿ����ֻ̰�Լһ�ϻ�������(master)��ߡ�  
ELEPHANT
	);
     set_perm_stat("dex", 5);
     set_perm_stat("str",10);
     set_perm_stat("kar",10);
     set_perm_stat("int", 5);
     set_perm_stat("pie",10);
     set_skill("dodge", 30);
     set("alignment",2000);
     set("max_hp",300);
     set("hit_points",300);
     set_natural_weapon(9, 4, 8);
     set_natural_armor(20, 18);
     set("special_defense", ([ "all" : 10, ]) );
     set("aim_difficulty", ([ "critical" : 10, ]) );
     set("exp_reward", 250);
     set("alt_corpse", SAULIN_MONSTER"fire_elephant");
     set_c_verbs(({ "%s���Ȳ�%s", "%s��ͷײ%s", "%s������ѹ%s" }));
     set_c_limbs(({ "����", "ͷ��", "�Ų�", "�ֱ�" }));
     set ("c_death_msg",
  "%s���˵: �ɶ񣬾����۸��ң��㲻Ҫ����! ���������µ�����! ���ֵĲ�Ҫ��!\n"
     );
	 set( "inquiry", ([
		  "master" : 
	      "�ҵ����˾��Ǵ������������������� .......\n" 
	      "            ���µ������������������ǧ��Ҫ�۸����!!\n"   ]) );
      set("tactic_func","crying");
}

int crying()
{
    if( random(20)<12 ) return 0;
    tell_room( environment(),
      "\n�����е�: ����ʲ�᣿��ͣ��! ������Ҫ�����!!\n" ,
      this_object()
    );
	return 1;
}

void die()
{
    tell_room( environment(this_object()),@C_DIE_MESSAGE
      
  ����ҽ�һ����ҡ��һ�䣬�����Ϊһֻ��ɫ������������������ӵ�����
    ��������������������ŭ�ĺ��������ڿ��С�
  ����е����ɶ�İ׳� !! ������ !! 
  
C_DIE_MESSAGE
      ,this_object()
    );
    ::die(1);
}
