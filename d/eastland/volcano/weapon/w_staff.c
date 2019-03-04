#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "wraith staff", "����Ȩ��" );
	add( "id", ({ "staff" }) );
	set_short("����Ȩ��" );
	set_long(
		"����һ�Ѱ����������ഫ��Ȩ�ȣ�����ĩ������һ��è��ʯ��\n"
                "è��ʯ��ͫ�����ƺ��������̹⡣\n" );
	set( "unit", "��" );
	set( "type", "blunt" );
//	set( "hit_func", "weapon_hit" );
	set( "weight", 130 );
	set( "weapon_class", 30 );
	set( "min_damage", 15 );
	set( "max_damage", 30 );
	set( "value", ({ 1000, "silver" }) );
	set( "no_sale", 1 );
}

int weapon_hit( object victim, int damage )
{
	object owner;
	int intelligence, sp;

	owner = environment();
	intelligence = owner->query_stat("int");
	sp = owner->query("spell_points");
	if( random(intelligence)>15 && sp > 5 ) {
		tell_object( owner, 
               "\n���Ȩ����è��ʯ��ͫ��ͻȻ�ſ�����ͫ�������һ���߲ʹ�â��"+victim->query("c_name")+
		"������ƺ�������ȥ\n�����һ��������Ȩ����ע���������....\n\n");
		tell_object( victim, 
                owner->query("c_name") + "��Ȩ����è��ʯ��ͫ��ͻȻ����һ���߲ʹ�â�����㣬�������ƺ�������ȥ\n");
		tell_room( environment(owner),
                        owner->query("c_name") + "��Ȩ���ϵ�ͫ��ͻȻ�ſ���һ���߲ʹ�â����"
                        + victim->query("c_name") + "���Ұ������������ȥ��\n",
			({ victim, owner }) );
	victim->receive_special_damage( "evil", intelligence );
	owner->receive_healing( intelligence );
	owner->add( "spell_points", -5 );
	owner->add( "alignment", -100 );
	return intelligence * 2;
	}
}
