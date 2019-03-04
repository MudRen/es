#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "broken_ice staff", "�Ʊ���" );
	add( "id", ({ "staff" }) );
	set_short( "�Ʊ���" );
	set_long(
		"����һ���޼᲻�ݣ����޲��Ƶ����ȣ���ͷ������̡�\n"
                "����������ɫ����˵����Ȼ������ԡ�\n" );
	set( "unit", "��" );
	set( "type", "blunt" );
//	set( "hit_func", "weapon_hit" );
	set( "weight", 130 );
	set( "weapon_class", 28 );
	set( "min_damage", 15 );
	set( "max_damage", 28 );
	set( "value", ({ 1000, "silver" }) );
}

int weapon_hit( object victim, int damage )
{
	object owner;
	int pietyy, sp;

	owner = environment();
	pietyy = owner->query_stat("pie");
	sp = owner->query("spell_points");
	if( random(pietyy)>17 && sp > 5 ) {
		tell_object( owner, 
                "\n����Ʊ����ϵļ��ͻȻ�����ֱ�����У�"+victim->query("c_name")+
		"��Ҫ����\n\n");
		tell_object( victim, 
                owner->query("c_name") + "���Ʊ����ϵļ��ͻȻ�����ֱ���������Ҫ����\n\n");
		tell_room( environment(owner),
                        owner->query("c_name") + "���Ʊ����ϵļ��ͻȻ�����ֱ������"
                        + victim->query("c_name") + "��Ҫ����\n\n",
			({ victim, owner }) );
	victim->receive_damage( 15+random(10) );
	owner->add( "spell_points", -5 );
	return 1;
	}
}
