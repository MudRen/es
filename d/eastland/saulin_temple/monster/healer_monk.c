#include "../saulin_temple.h"

inherit "/d/eastland/saulin_temple/monster/saulin.c";

void create()
{
	object ob1;
	::create();
	set_level(16);
	set_name( "blessing monk", "ҩ���� ��ɮ" );
	add( "id", ({ "blesser","monk","blessing" }) );
	set_short( "ҩ���� ��ɮ" );
	set_long(@C_LONG
�㿴��һ����ɫ���Ƶ�ɮ�ˣ�������һ����ɮ����ö�������������
Э������ͬ����ս��
C_LONG
	);
	set("unit", "��" );
	set("race", "human" );
	set("gender", "male" );
	set("alignment", 200 );
	set("special_defense", ([ "all": 30, "none" : 10, ]) );
	set("aim_difficulty", ([ "critical" : 30, "vascular" : 30, ]) );
	set_natural_armor( 70, 30 );
	set_natural_weapon( 8, 10, 20 );
	set("max_hp", 550);
	set("hit_points", 550);
	set("max_fp", 1400);
	set("force_points", 1400);
	set("wealth/gold", 20 );
	set("wimpy", 30 );
	set("killer",1);
	set("tactic_func", "my_tactic");
	set_perm_stat("str", 15);
	set_perm_stat("dex", 25);
	set_perm_stat("int", 28);
	set_perm_stat("kar", 24);
	set_perm_stat("pie", 28);
	set_skill( "dagger", 50 );
	set_skill( "dodge", 80 );
	set_skill( "anatomlogy", 100 );
	set_temp( "aiming_loc", "ganglion" );
	set( "chat_chance", 10 );
	set( "att_chat_output", ({
		"��ɮ˵��: ���ǻ��Ƿ����ɣ����ǳŲ�ס�ĵ� !\n",
		"��ɮ˵��: ����ֻҪ�Թ����־͸����Ǿ�����Ϊ�����ǵ�!\n",
        "��ɮ��ʲ���������ӷ�! ʩ����Ϊ��˲�����Ī��Сɮ������!!\n"
    }) );

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
		"��ɮ�����: ҩ������ ! �뱣�������µ�ʹͽ�� ! .....\n"
		"\n�������һ��������ɫ�Ĺ�â����������ɮ���ǵ����ϡ�\n\n"
		, this_object()
	);
	people = all_inventory( environment() );
	people->heal_saulin(35);
	return 1;
}

void help_me_saulin(object who, object victim)
{
	if( !attackers || member_array(victim, attackers)==-1 )
		kill_ob(victim);
	tell_room( environment(), 
		"��ɮͦ��....Э��" + who->query("c_name") + "��ս��\n"
	       , this_object()
	);
}
