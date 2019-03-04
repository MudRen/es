#include "../saulin_temple.h"

inherit "/d/eastland/saulin_temple/monster/saulin.c";

void create()
{
	::create();
	set_level(15);
	set_name( "Bonze", "������ ��ɮ" );
	add( "id", ({ "bonze","monk" }) );
	set_short( "������ ��ɮ" );
	set_long(
		"�㿴��һ����ɮ��������Ѱ�Ҷ�����Ҫ��ʦ�岮��ǰһչ�Լ���ѧ��\n"
	);
	set("unit", "��" );
	set("race", "human" );
	set("gender", "male" );
	set("alignment",  300 );
	set("max_hp", 695);
	set("hit_points", 695);
	set("max_fp", 2450);
	set("force_points", 2450);
	set("special_defense", ([ "all" : 35, "none" : 21 ]) );
    set("aim_difficulty", ([ "critical" : 45, "vascular" : 35 ]) );
  	set_natural_weapon( 20, 10, 20 );
  	set_natural_armor( 78, 30 );
	set("wealth/gold", 18 );
	set("aggressive", 1 );
	set("killer", 1 );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 18 );
	set_skill( "longblade", 80 );
	set_skill( "parry", 60 );
	set_skill( "dodge", 60 );
	set_skill( "defend", 60 );
	set( "chat_chance", 10 );
	set( "att_chat_output", ({
		"��ɮ���: ����÷�ү�ȱ������ǰ�!!\n",
		"��ɮ˵��: ���־͸��Ҿ�����������Щ��!\n",
		"��ɮ˵��: ������ʦ�岮�����ֵĺ�ȥ����������������ΰ�!\n"
	}) );

	wield_weapon( SAULIN_OBJ"blade4" );
	equip_armor( SAULIN_OBJ"necklace" );
}

void help_me_saulin(object who, object victim)
{
	object *tmp;

	if( who->id("monk") ) return;
	tmp = who->query_temp("protectors");
	if( !tmp || member_array(this_object(), tmp)==-1 ) {
		who->add_temp("protectors", ({this_object()}) );
		add_temp( "protectees", ({who}) );
	}
	if( !attackers || member_array(victim, attackers)==-1 )
		kill_ob(victim);
	tell_room( environment(), 
		"��ɮͦ����" + who->query("c_name") + "��\n"
		, this_object()
	);
}
