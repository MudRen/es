#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "crimsom longsword", "����" );
	add( "id", ({ "longsword", "sword" }) );
	set_short( "�ʺ�ɫ����" );
	set_long(
		"����һ������������ʺ�ɫ���еĳ�����\n" );
	set( "unit", "��" );
	set( "type", "longblade" );
	set( "hit_func", "weapon_hit" );
	set( "weight", 100 );
	set( "weapon_class", 18 );
	set( "min_damage", 9 );
	set( "max_damage", 18 );
	set( "value", ({ 450, "silver" }) );
}

int weapon_hit( object victim, int damage )
{
	object owner;
	int intelligence, sp;

	owner = environment();
	intelligence = owner->query_stat("int");
	sp = owner->query("spell_points");
	if( random(intelligence)>12 && sp > 5 ) {
		tell_object( owner, 
			"\n����ʺ�ɫ����ͻȻ����һ�������һ𣬽����յ�ͨ�죡\n\n"
		        ); 
		tell_room( environment(owner), 
			owner->query("c_name") + "���ʺ�ɫ����ͻȻ����һ�������һ𣬽����յ�ͨ�죡\n",
			owner );
		victim->receive_special_damage( "fire", intelligence );
		owner->add( "spell_points", -5 );
		return intelligence;
	}
}
