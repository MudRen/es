#include <mudlib.h>

inherit MONSTER;

void create()
{
	object obj;

	::create();
	set_level(5);
	set_name( "beggar", "��ؤ" );
	set_short( "��ؤ" );
	set_long(
		"����ֳ��������ؤ��̰����������Ŀڴ���\n"
	);
	set( "gender", "male" );
	set( "alignment", -400 );
	set_perm_stat( "dex", 10 );
	set_perm_stat( "int", 8 );
	set_perm_stat( "kar", 10 );
	set_skill( "dodge", 50 );
	set_skill( "dagger", 50 );
	set( "tactic_func", "my_tactic" );
	set( "natural_armor_class", 15 );
	set( "natural_weapon_class1", 8 );
	set( "natural_min_damage1", 4 );
	set( "natural_max_damage1", 6 );

	obj = new( "/d/eastland/haiwei/obj/bag" );
	obj->move(this_object());
}

int my_tactic()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
	if( victim->query("stop_attack") ) return 0;
	tell_object( victim, 
		"��ؤͻȻ����һ�ţ������߷�һ��������\n");
	tell_room( environment(), 
		"��ؤͻȻ����һ�ţ���" + victim->query("c_name") + "�߷�һ��������\n",
		({ victim, this_object() }) );
	victim->block_attack(6);
	victim->set_temp("msg_stop_attack", 
		"( ������ˤ���ڵأ��޷������� )\n" );
	return 1;
}
