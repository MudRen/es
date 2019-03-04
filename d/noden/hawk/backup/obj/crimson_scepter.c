#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "crimson scepter", "Ȩ��" );
	add( "id", ({ "mace","scepter" }) );
	set_short( "�ʺ�ɫȨ��" );
	set_long(
		"����һ���ʺ�ɫ��Ȩ�ȣ�����ĩ������һ��������ֻ���Ƕ�ħ��ͷ��\n" );
	set( "unit", "��" );
	set( "type", "blunt" );
	set( "hit_func", "weapon_hit" );
	set( "weight", 150 );
	set( "weapon_class", 28 );
	set( "min_damage", 16 );
	set( "max_damage", 27 );
	set( "value", ({ 950, "silver" }) );
	set( "no_sale", 1 );
}

int weapon_hit( object victim, int damage )
{
	object owner;
	int intelligence, sp;

	owner = environment();
	intelligence = owner->query_stat("int");
	sp = owner->query("spell_points");
	if( random(intelligence)>19 && sp > 5 ) {
		tell_object( owner, 
			"\n����ʺ�ɫȨ���ϵĶ�ħͷͻȻ�����۾�����"+victim->query("c_name")+
			"����ҧ��һ��Ѫ���ܵ��⣡\n�����һ��������Ȩ����ע���������....\n\n"
			);
		tell_object( victim, 
			owner->query("c_name") + "���ʺ�ɫȨ���ϵĶ�ħͷͻȻ�����۾�������һ�ڴ�������ҧ��һ��Ѫ��\n"
			"�ܵ��⣡\n"
                        );
       		tell_room( environment(owner),
			owner->query("c_name") + "���ʺ�ɫȨ���ϵĶ�ħͷͻȻ�����۾������Ҵ�"
			+ victim->query("c_name") + "����ҧ��һ��Ѫ���ܵ��⣡\n"
			,({ victim, owner }) );
		victim->receive_special_damage( "evil", intelligence );
		owner->receive_healing( intelligence );
		owner->add( "spell_points", -5 );
		owner->add( "alignment", -100 );
		return intelligence * 2;
	}
}
