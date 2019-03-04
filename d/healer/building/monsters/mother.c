#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "Mother Hsin", "�̴���" );
	add( "id", ({ "mother", "hsin", "mother hsin" }) );
	set_short( "�̴���" );
	set_long(
		"�̴��������ϵ��Ӷ�������ܻ�����ɳ��, ����Ľ���ϵ�������\n"
		"�˵�����, ��Ը��æ�չ˲���, ��������վ�����, ��Ϊ����\n"
		"�����̴�������չ˲�����, ������һЩҽ����Ʒ��\n"
	);
	set( "race", "human" );
	set( "gender", "female" );
	set_perm_stat( "int", 28 );
        set_perm_stat( "pie", 22 );
        set_perm_stat( "con", 22 );
        set_perm_stat( "kar", 27 );
	set_skill( "dodge", 95 );
	set_skill( "dagger", 95 );
	set_skill( "anatomlogy", 95 );
	set( "aiming_loc", "vascular" );
	set( "max_hp", 500 );
	set( "hit_points", 500 );
         set_natural_armor( 30, 10 );
	set_natural_weapon( 45, 20, 30 );
	set( "special_defense", ([ "all": 50,"none":60]) );
        set( "aim_difficulty",([ "weakest":10,"vascular":15 ]) );
	set( "alignment", 1400 );
	wield_weapon( "/d/healer/building/weapons/topknot" );
        equip_armor( "/d/healer/building/armors/jade_ring" );
}
