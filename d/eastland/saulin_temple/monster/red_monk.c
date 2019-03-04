#include "../saulin_temple.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "rohan of red pallium", "�޺��ú����޺�" );
	add( "id", ({ "monk","rohan" }) );
	set_short( "�޺��ú����޺�" );
	set_long(
		"�㿴��һ���޺��õĺ����޺��������������޺��á�\n"
	);
	set( "unit", "��" );
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment",  1500 );
	set("max_hp", 465);
	set("hit_points", 465);
	set("max_fp", 1800);
	set("force_points", 1800);
	set_natural_weapon( -15, -10, -5 );
	set_natural_armor( 45, 28 );
	set( "wealth/gold", 15 );
	set_perm_stat( "str", 21 );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "con", 25 );
	set("special_defense", ([ "all" : 25, "none" : 7 ]) );
	set("aim_difficulty", ([ "critical" : 30, "vascular" : 25, ]) );
	set_skill( "longblade", 100 );
	set_skill( "parry", 100 );
	set("defense_type","parry");
	set("attack_skill",CLASS"wu_sur");
	set("gonfus/wu_sur",100);
	set( "chat_chance", 10 );
	set( "att_chat_output", ({
         "�޺��ú����޺����:���������޺��õ����ڣ������ַ��޺��� ����\n",
		 "�޺��ú����޺����:��ʦ�ֵ���! ��Щ�޳ܵĻ���������!!������ѵ����!��\n",
		 })
	 );

	wield_weapon( SAULIN_OBJ"blade3" );
	equip_armor( SAULIN_OBJ"red_pallium" );
//	equip_armor( SAULIN_OBJ"eye" );
	equip_armor( SAULIN_OBJ"glove3a" );
}

