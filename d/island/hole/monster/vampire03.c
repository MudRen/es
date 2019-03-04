#include <../hole.h>

inherit REPORT;
inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name( "Vampire","С��Ѫ����" );
	add("id",({ "kill_vampire2","bat","vampire" }) );
	set_short( "С��Ѫ����" );
	set_long(@LONG
    һֻ��Ѫ�������������ұ��ϣ�һ˫������۾��������㲻��
���ƺ���������Ҫ���㵱����͡����������������֮ǰ�Ͽ��뿪���
LONG
		);
	set( "alignment",-500 );
	set_perm_stat( "dex",15 );
	set_perm_stat( "kar",25 );
	set_skill( "dodge",45 );
	set_natural_armor( 60,10 );
 	set_natural_weapon( 30,5,20 );
 	set( "killer",1 );
	set_c_limbs( ({ "ͷ��","����","���","צ��" }) );
	set_c_verbs( ({ "%s����������������ҧ��%s","%s��������צץ��%s","%s�����ĳ������%s" }) );
	set( "tactic_func","my_tactic" );
}

int my_tactic()
{
	object victim;
	string him;

	if( random(20)>3 || !(victim=query_attacker()) ) return 0;
	else
	{
	him = victim->query( "c_name" );
	tell_object(victim,"\n��Ѫ����ɵ���Ĳ����Ϻݺݵ�����һ�����Ѫ\n\n");
	tell_room(environment(this_object()),
	"��Ѫ����ͻȻ�ɵ�"+him+"�Ĳ����Ϻݺݵ�����һ�����Ѫ\n\n",victim);
	victim->receive_damage( 10 + random(15) );
	report( victim );
	return 1;
	}
}
