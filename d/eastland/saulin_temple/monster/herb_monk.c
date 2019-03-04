#include "../saulin_temple.h"

inherit "/d/eastland/saulin_temple/monster/saulin.c";

void create()
{
	object ob1;
	::create();
	set_level(13);
	set_name( "herb monk", "ҩ������ҩɮ" );
	add( "id", ({ "monk","herb" }) );
	set_short( "ҩ������ҩɮ" );
	set_long(
		"�㿴��һ����ɫ���Ƶ�ɮ�ˣ����������Ǿ����������ˡ�\n"
	);
	set("unit", "��" );
	set("race", "human" );
	set("gender", "male" );
	set("alignment", 600 );
	set("special_defense", ([ "all": 30, "none" : 10, ]) );
	set("aim_difficulty", ([ "critical" : 30, "vascular" : 30, ]) );
	set_natural_armor( 39, 22 );
	set_natural_weapon( -11, 1, 2 );
	set("max_hp", 550);
	set("hit_points", 550);
	set("max_fp", 1400);
	set("force_points", 1400);
	set("force_effect",2);
	set("wealth/gold", 20 );
	seteuid( getuid() );
	set("wimpy", 40 );
	set("tactic_func", "my_tactic");
	set_perm_stat("str", 15);
	set_perm_stat("dex", 26);
	set_perm_stat("int", 20);
	set_skill( "dagger", 70 );
	set_skill( "dodge", 80 );
	set_skill( "anatomlogy", 100 );
	set_temp( "aiming_loc", "weakest" );
	wield_weapon( SAULIN_OBJ"healer_dagger1" );
	equip_armor( SAULIN_OBJ"cloth3" );
	equip_armor( SAULIN_OBJ"cloak3" );
	ob1 = new( SAULIN_OBJ"red_pill" ); 
	ob1->move(this_object());
}

int my_tactic()
{
	object *people;
	
	if( random(20) > 5 ) return 0;
	tell_room( environment(this_object()), 
		"��ҩɮ�૵���ҩ������ ! �뱣�������µ�ʹͽ�� ! .....\n"
		"\n�������һ��������ɫ�Ĺ�â��������ҩɮ�����ϡ�\n\n"
		, this_object()
	);
	this_object()->heal_saulin(35);
	return 1;
}

