#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "Evil Sword");
	add( "id", ({ "sword" }) );
	set_short( "���� ����" );
	set_long
		"����һ�Ѵ�˵�е����� ����,�����Ϸ���һ������Ĺ�â\n" 
		"��˵�˵�������һ�����ص�����\n");
	set( "unit", "��" );
	set( "type", "longblade" );
//	set( "hit_func", "weapon_hit" );
	set( "weight", 150 );
	set( "weapon_class", 35 );
	set( "min_damage", 20 );
	set( "max_damage", 40 );
	set( "value", ({ 1950, "silver" }) );
}

int weapon_hit( object victim, kar damage )
{
	object owner;
	kar karma, hp;

	owner = environment();
	karma = owner->query_stat("kar");
	hp = owner->query("hit_points");
	if( random(karma)>19 && hp > 5 ) {
		tell_object( owner, 
			"\n��ĸо������� ������ʼ�����������������"+victim->query("c_cap_name")+
			"����ҧ��һ��Ѫ���ܵ��⣡\n�����һ��������Ȩ����ע���������....\n\n":
			
			 );
		tell_object( victim, can_read_chinese(victim)?
			owner->query("c_cap_name") + "���ʺ�ɫȨ���ϵĶ�ħͷͻȻ�����۾�������һ�ڴ�������ҧ��һ��Ѫ��\n"
			"�ܵ��⣡\n":
			"The devil head on " + owner->query("cap_name") + "'s crimson scepter suddenly\n"
			"come alive and bite a piece of flesh off you!\n" );
		tell_room( environment(owner), ({
			"The devil head on " + owner->query("cap_name") + "'s crimson scepter suddenly\n"
			"come alive and bite a piece of flesh off its victim!\n",
			owner->query("c_cap_name") + "���ʺ�ɫȨ���ϵĶ�ħͷͻȻ�����۾������Ҵ�"
			+ victim->query("c_cap_name") + "����ҧ��һ��Ѫ���ܵ��⣡\n"}),
			({ victim, owner }) );
		victim->receive_special_damage( "evil", intelligence );
		owner->receive_healing( intelligence );
		owner->add( "spell_points", -5 );
		owner->add( "alignment", -100 );
		return intelligence * 2;
	}
}