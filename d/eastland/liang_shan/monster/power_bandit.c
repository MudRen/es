#include "../takeda.h"
inherit "/d/eastland/liang_shan/monster/liang_shan_bandit";

void create()
{
	int i;
	i = random(2);
	::create();
	set_level(10);
	set_name( "mountain thief", "��ǿ��ɽ��" );
	add( "id", ({ "thief", "bandit" }) );
	set_short( "��ǿ��ɽ��" );
	set_long(
		"���ɽ��һ������ɽ������������һ���Ӣ��֮����������̫���ǡ�\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -300 );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "kar", 15 );
	set_skill( "unarmed", 60 );
	set_skill( "parry", 60 );
	set_skill( "dodge", 60 );
	set( "hit_points", 230 );
	set( "max_hp", 230 );
	set( "wealth/gold", 18 );
	set( "special_defense", (["all": 13 ]) );
	set_natural_weapon( 7, 7, 7 );
	set_natural_armor( 20, 35 );
	wield_weapon( TWEAPON"tiger_finger" );
	equip_armor( TARMOR"vest");
	set( "tactic_func", "my_tactic" );

}
int my_tactic()
{
	int my_dex,my_str,my_kar,num;
	object victim;

	if( random(50)>2 || !(victim= query_attacker()) ) return 0;
	if( victim->query("stop_attack") ) return 0;
	tell_object(victim,set_color( "˵ʱ�٣���ʱ�죬һ����ǿ��ɽ���������г��˳�������"
        "ʩչ���ı�ɱ����ʮ�������ۡ�\n","HIM",victim));
	tell_room(environment(this_object()),set_color("˵ʱ�٣���ʱ�죬һ����ǿ��ɽ���������г��˳�����"
	+victim->query("c_name")+"ʩչ���ı�ɱ����ʮ�������ۡ�\n","HIM",victim),victim);
	my_dex = victim->query_stat("dex");
	my_kar = victim->query_stat("kar");
	my_str = victim->query_stat("str");
	num = (my_dex + my_kar + my_str)/5;
	if( random(num) > 3 ) {
	tell_object(victim,set_color( "�����������ǿ��ɽ���Ĺ�����˳������ƨƨ��ȥ��\n","HIY",victim));
	tell_room(environment(this_object()),set_color(victim->query("c_name")+
	"����������ǿ��ɽ���Ĺ�����˳������ƨƨ��ȥ��\n","HIY",victim),victim);     
	if( random(10) < 5 ) {
	command("moan");
	return 1;
	}        
	tell_object(victim,set_color("���ϼ�ǿ��ɽ����һ��ת��ץס��Ĵ������һ̧����ˤ���ڵز��ܶ���...\n","HIG",victim));
	tell_room(environment(this_object()),set_color("��ǿ��ɽ����һ��ת��ץס"+victim->query("c_name")+
	"�Ĵ������һ̧��ʹ��ˤ���ڵز��ܶ���...\n","HIG",victim),victim);
	victim->block_attack(2);
	victim->set_temp("msg_stop_attack", "\n�� ������ˤ���ڵ��޷����� ��\n\n ");
	victim->receive_damage(5);
	return 1;
	}
	victim->block_attack(3);
	tell_room(environment(this_object()),set_color(
	    "��ǿ��ɽ��˵��:���û��ᣬ�����ǿ���....�������е�ɽ��һӿ����...\n","HIG",victim));
	victim->set_temp("msg_stop_attack", "\n�� �����ڱ���ǿ��ɽ����ס���������ã��޷����� ��\n\n");
	victim->receive_damage(10);
	return 1;
}

void die()
{
    object *tmp,leader;
 //   leader = present("leader"); 
    leader = query("master");
	if ( !leader ) {
    ::die();
	return;
    }
    tmp = leader->query_temp("party_members");
    tmp -= ({ this_object() });
    leader->set_temp("party_members",tmp);
    leader->set_temp("embattle_busy",0);
    leader->add("party_num",-1);
    tell_room(environment(this_object()),
    "��ǿ��ɽ��˵��:����������ǿ? �����ȳ�һ�£�����ȥ����....��\n");
    command("wave");
    command("drop all");
    ::die(1);
 }
