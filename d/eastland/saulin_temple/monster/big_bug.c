#include "../saulin_temple.h"
#include <stats.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(12);
	set_name("Mami mushroom", "��֥����");
	add("id",({"mami","mushroom"}));
	set_short("��֥����");
	set_long(
	    "һֻ����ΪС�����۸�����������֥���裬�����÷�ŭ���۹�����㡣\n"
	);
	set("unit", "ֻ");
	set("alignment", 350 );
	set("killer",1);
	set("max_hp", 500);
	set("hit_points", 500);
	set_perm_stat("dex",20);
	set_perm_stat("str",16);
	set_perm_stat("int",18);
	set_natural_weapon(20, 12, 23);
	set_natural_armor(60, 24);
	set( "special_defense", ([ "all" : 40, "none" : 20 ]) );
	set( "aim_difficulty", ([ "ganglion" : 65, ]) );
	set( "unbleeding", 1);
	set( "tactic_func", "sleepy" );
	set( "alt_corpse", SAULIN_OBJ"big_pill" );
	set_c_verbs(({ "%s��ͷײ%s", "%s������ײ%s" }));
	set_c_limbs(({ "����", "ͷ��" }));
	set("c_death_msg","%sͻȻ�������������ڵ���... �����ˡ�\n");
}

int sleepy()
{
	object victim;

	if( random(20)>6 || !(victim = query_attacker()) ) return 0;
    if( victim->query("stop_attack") ) return 0;
    tell_object( victim, 
      "��֥����ɢ����һ����������е������˯!!\n");

    tell_room( environment(this_object()), 
      "��֥���裬ɢ����һ�����ص���Ϣ��"+victim->query("c_name")+"�ԵĲ�������!!\n",
      ({ victim, this_object() })
    );
    victim->block_attack(6);
    victim->set_temp("msg_stop_attack", 
       "( ������ȫ��������ֻ��úõ�˯һ��! )\n"
    );
    return 1;
}
