#include <../hole.h>

//inherit REPORT;
inherit WEAPON;

void create()
{
	set_name( "Fire Scale Sword","���뽣" );
	add( "id",({ "sword" }) );
	set_short( "���뽣" );
	set_long(@LONG
	��ѽ�������һƬ���������Ƭ���ǰѺ���
	�ĺñ�����
LONG
		);
	set( "unit","��" );
	set( "type","shortblade" );
	set( "weapon_class",40 );
	set( "min_damage",20 );
	set( "max_damage",45 );
	set( "special_damage",25 );
	set( "weight",150 );
	set( "second",1 );
	set( "value",({ 3600,"silver" }) );
	set_c_verbs( ({ "%s�����Ի��˸�Ȧ��ʹ����������ǡ�����%s",
			"%s�ų�ѣĿ�⻪���������룬ʹ������������������%s",
			"%sȸԾ������һ�����������գ�ʹ�����������졹����%s",
			"%s�������ܽ��������������ʹ��������ʴ�ա���ס%s" }) );
//	set( "hit_func","fire_damage" );
}

int fire_damage(object victim,int dam)
{
	object holder;
	int max;
	string msg1,msg2,him,me;

	dam=this_object()->query( "special_damage" );
	if ( !victim ) return 0;
	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
	if ( (int)holder->query_skill( "shortblade" )<88 ){
		tell_object( holder,"\n��Ļ��뽣��Ȼӿ��һ�ɺ�ɫ���潫��ȫ���յ���ʹ������\n" );
		holder->receive_damage( dam+random(15) );
//		report( holder );
		victim->set( "last_attacker",holder );
		return dam;
	}
	else{
		if ( max = random(75)< 20 ){
			him=victim->query( "c_name" );
			me=holder->query( "c_name" );
			tell_object( holder,set_color("��Ļ��뽣��Ȼӿ��һ�ɺ�ɫ���潫"+him+"�ո����ڣ�\n","HIR") );
			tell_object( victim,set_color( me+"�Ļ��뽣��Ȼӿ��һ�ɺ�ɫ���潫��ȫ���յ���ʹ������\n","HIR") );
			tell_room( environment(holder),set_color(me+"�Ļ��뽣��Ȼӿ��һ�ɺ�ɫ���潫"+him+"�ո����ڣ�\n","HIR"),({ holder,victim }) );
			victim->receive_damage( dam+max );
//			report( victim );
			victim->set( "last_attacker",holder );
			return dam;
		}
	return 0;
	}
}
	