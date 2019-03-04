#include <../hole.h>

inherit REPORT;
inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "Vampire","��Ѫ��" );
	add("id",({ "kill_vampire1","vampire" }) );
	set_short( "��Ѫ��" );
	set_long(@LONG
    һ������Ѫɫ����Ѫ��
LONG
		);
	set( "alignment",-5000 );
	set( "exp_reward",45000 );
	set( "max_hp",7500 );
	set( "hit_points",7500 );
	set( "time_to_heal",8 );
	set_perm_stat( "dex",25 );
	set_perm_stat( "str",15 );
	set_perm_stat( "int",15 );
	set_perm_stat( "kar",25 );
	set_natural_armor( 100,0 );
 	set_natural_weapon( 75,25,50 );
//	set( "unbleeding",1 );
	set_c_limbs( ({ "ͷ��","����","���","צ��" }) );
	set_c_verbs( ({ "%s����������������ҧ��%s","%s��������צץ��%s","%s�����ĳ������%s" }) );
	set( "tactic_func","my_tactic" );
}

int my_tactic()
{
	object obj1,obj2,obj3,victim;
	string him;

	if( !(victim=query_attacker()) ) return 0;
	if( random(20)< 3 && !present( "kill_vampire2",environment(this_object()) ) )
	{
	him = victim->query( "c_name" );
	tell_room( environment(this_object()),"\n����Ѫ�ٻ�����Ѫ���𹥻����ˡ�\n\n" );
	obj1=new( HMONSTER"vampire03" );
	obj2=new( HMONSTER"vampire03" );
//	obj3=new( HMONSTER"vampire03" );
	obj1->move( environment(this_object()) );
	obj2->move( environment(this_object()) );
//	obj3->move( environment(this_object()) );
	return 1;
	}
}

void die()
{
	object killer;
	
	killer=query( "last_attacker" );
	tell_room(environment(),@ALONG

��Ѫ������������˵�����������ǲ����ܵġ����������̫�磬
		    �һ��ٻ����ı���ġ�
		    
    ˵����仰����Ѫ����һֻС����Ѹ����ʧ����Ӱ���١�

ALONG
		);
        if( (int)killer->query_quest_level("q_vampire")<1){
        tell_object(killer,set_color("��ϲ������ˡ���ʿ�ķ��ա���������20000�㾭��ֵ��\n","HIY",killer));
        killer->set_explore("island#10");
	killer->gain_experience( 20000 );
	killer->finish_quest("q_vampire",1);
	}
	::die();
}
