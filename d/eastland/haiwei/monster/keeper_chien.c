#include <mudlib.h>

inherit MONSTER;

void create()
{
	object ob1, ob2, ob3;

	::create();
	set_level( 7 );
	set_name( "keeper", "Ǯ����" );
	add( "id", ({ "chien" }) );
	set_short( "�󳯷�Ǯ����" );
	set_long(@C_LONG
Ǯ��������ҵ��̵Ĵ󳯷����ȥ����ҵ��̿���ʱ�Ӿ��������˵صġ�
C_LONG
	);
	set( "gender", "male" );
	set( "alignment", 140 );
	set_perm_stat( "int", 15 );
	set_perm_stat( "kar", 20 );
	set_skill( "dodge", 50 );
	set( "natural_armor_class", 40 );
	set( "natural_defense_bonus", 15 );
	set( "natural_weapon_class1", 12 );
	set( "natural_min_damage1", 6 );
	set( "natural_max_damage1", 8 );
	set( "wealth/gold", 20 );

	ob1 = new( "/d/eastland/haiwei/obj/round_cap" );
	ob1->move(this_object());
	equip_armor(ob1);
	ob2 = new( "/d/eastland/haiwei/obj/long_garb" );
	ob2->move(this_object());
	equip_armor(ob2);
	ob2 = new( "/d/eastland/haiwei/obj/jade_ring" );
	ob2->move(this_object());
	equip_armor(ob2);
}


int eat_pill()
{
	if( random(20)<6 && (int)query("hit_points") < 80 ) {
		tell_room( environment(),
			"Ǯ�����ӿڴ���ȡ��һ����ɫҩ�裬Ȼ��ܿ�ذ�ҩ�����¡�\n"
		 );
		receive_healing( 50 );
	}
}
