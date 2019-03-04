#include "../goomay.h"

inherit MONSTER;

void create()
{
	::create();
	set_level( 3 );
	set_name( "smith", "����" );
	set_short( "����" );
	set("long",
		"@@query_c_long"
	);
	set( "gender", "male" );
	set( "race", "dwarf" );
	set( "alignment", 200 );
	set("max_hp", 100);
	set("hit_points", 100);
	set( "wealth/silver", 10 );
	set( "tactic_func", "my_tactic" );
	set_natural_weapon( 1, 2, 2 );
	set_natural_armor( 30, 10 );
	wield_weapon( Obj"hammer" );
}

string query_c_long()
{

	if( (int)this_player()->query_quest_level("Goddess_statue") > 1 )
		return "����������ڷ�������Ϊ����¯��һֱ����������\n";
	else return "�����������ڵع��������������������ƺ��������С�\n";
}

int my_tactic()
{
	object victim, weapon;
	int wc;

	if( random(20)>4 ) return 0;
	if( !(victim= query_attacker()) ) return 0;
	if( !(weapon = victim->query("weapon1")) )
		weapon = victim->query("weapon2");
	if( !weapon ) return 0;
	tell_room( environment(), 
		"�����߾���������" + victim->query("c_name") + "��" + 
		weapon->query("c_name") + "�����㡸��ॡ�һ��������ȥ��\n",
		({ this_object(), victim }) );
	tell_object( victim, 
		"�����߾������������" + 
		weapon->query("c_name") + "�����㡸��ॡ�һ��������ȥ��\n");
	wc = weapon->query("weapon_class");
	if( !weapon->query("damaged") ) {
		weapon->add( "short", " (����)" );
	}
	weapon->add( "damaged", wc/2 );
	weapon->add( "weapon_class", - wc/2 );
	victim->calc_weapon_class();
	return 1;
}
