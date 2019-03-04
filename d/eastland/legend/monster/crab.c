#include <mudlib.h>
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(6);
       set_name( "huge crab", "���з" );
       add("id",({"crab"}) );
       set_short( "���з" );
       set("unit","ֻ");
        set_long(
       "           ��        ��
           �� ��  �� ��
           ��\\�ء���/��     ����һֻ����˶��Ļ�з������ʮ������
           ����    ����
            ����������\n");
       set_perm_stat("dex", 4);
       set ("natural_weapon_class1", 10);
       set ("natural_min_damage1",5);
       set ("natural_max_damage1", 10);
       set ("natural_armor_class", 1);
       set_c_verbs(({"%s�����ľ�����%s����"}));
       set_c_limbs(({"����","ͷ��"}));
       set ("exp_reward", 200);
       set ("tactic_func", "fire_ball");
}

void fire_ball()
{
    object victim;
    if( !(victim=query_attacker()) || random(8)> 1 ) return 0;
    tell_object( victim,
      "��зͻȻ�ſ����죬�³�һ�Ż����\n" );
    tell_room( environment(this_object()),sprintf(
      "��зͻȻ�ſ����죬��%s�³�һ�Ż����\n",victim->query("c_name"))
     , ({ victim, this_object() })
    );
    victim->receive_special_damage("fire", 6, 1 );
}

