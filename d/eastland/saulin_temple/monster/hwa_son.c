#include <../saulin_temple.h>

inherit MONSTER;

void create()
{
	object obj;

	::create();
	set_level( 10);
	add("id",({"monk","son","hwa"}) );
        set_name( "Hwa son", "����" );
	set_short("����" );
	set_long(@C_LONG
��������,һ����Ե... ����Ҳ���˺ܶ����ķ�������,�����Ǹ������˺���
����ָ������,�в��������,���Ҹ������ ����...
C_LONG
	);
	set( "race","lizardman"); 
        set( "gender", "male" );
	set( "alignment",  300 );
	set_perm_stat( "dex", 16 );
	set_perm_stat( "str", 18 );
	set_perm_stat( "kar", 12 );
	set_skill( "dodge", 50 );
	set_skill( "unarmed", 80 );
	set( "tactic_func", "my_tactic" );
	set_natural_weapon(19, 10, 20);
	set_natural_armor(50, 18);
        equip_armor(SAULIN_OBJ"silk_tail");

}

int my_tactic()
{
	object victim;

	if( random(20)>5 || !(victim= query_attacker()) ) return 0;
	if( victim->query("stop_attack") ) return 0;
	tell_object( victim,
		    "����β��һ˦,˫�ֺ�ʮ.... ʹ��������ָ���������Ѩ����\n\n");
	tell_room( environment(), 
		  sprintf("����ͻȻ����һָ����ס��%s��Ѩ����\n", victim->query("c_name")),
		({ victim, this_object() }) );
	victim->block_attack(6);
	victim->set_temp("msg_stop_attack", 
			 "( ���Ѩ������,һʱ֮���޷�����...... )\n" );
	return 1;
}
