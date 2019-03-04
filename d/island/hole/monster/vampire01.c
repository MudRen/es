#include <../hole.h>

inherit REPORT;
inherit MONSTER;

void create()
{
	::create();
	set_level(16);
	set_name( "Vampire","��Ѫ����" );
	add("id",({ "vampire","bat" }) );
	set_short( "��Ѫ����" );
	set_long(@LONG
    һֻ�޴����Ѫ�������������ұ��ϣ�һ˫������۾���������
���ţ��ƺ���������Ҫ���㵱����͡����������������֮ǰ�Ͽ���
�����
LONG
		);
	set( "alignment",-3000 );
	set( "exp_reward",100 );
	set( "max_hp",9000 );
	set( "hit_points",9000 );
	set( "time_to_heal",4 );
	set_perm_stat( "dex",30 );
	set_perm_stat( "str",25 );
	set_perm_stat( "int",15 );
	set_perm_stat( "kar",25 );
	set_skill( "dodge",100 );
	set_skill( "tactic",100 );
	set_natural_armor( 150,80 );
 	set_natural_weapon( 90,19,43 );
	set( "special_defense",([ "all":80,"none":80 ]) );
	set( "aim_difficulty",([ "ganglion":100,"critical":80 ]) );
	set( "stun_diffculty",100 );
	set( "tactic","assault" );
	set( "unbleeding",1 );
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
	victim->receive_damage( 20 + random(30) );
	report( victim );
	return 1;
	}
}

void change( object what, object player )
{
	object ob;
	ob = new( HMONSTER"vampire02" );
	ob->move( environment( what ) );
	tell_object( player,@ALONG
     
��Ѫ���𷢳�һ���������ᣬͻȻ���һ������Ѫɫ����Ѫ��!
��Ѫ�����������˵�����������㾹�һ����Ҷ�������У�ȥ����!

ALONG
		);       
	ob->kill_ob( player );
	what->remove();
}
