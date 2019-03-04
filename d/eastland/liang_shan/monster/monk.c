#include "../takeda.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(18);
    set_name("Lu Zhi Shen ","³����");
    add("id",({"lu","zhi","shen","monk"}) );
    set_short("³����");
	set_long(@C_LONG
��Ż����У�ԭ��³���Ϊ���ǹ����ˣ�������һ���������š�������
��������ְ������������ȭ����һ�ˣ�ĿǰΪ��ɽ������ͳ��֮һ��
C_LONG
	);
    set("alignment",100);
    set( "gender", "male" );
    set( "race", "human");
    set( "unit", "��" );
    set_perm_stat( "dex",20);
    set_perm_stat( "str",30);
    set_perm_stat( "int",15);
    set_perm_stat( "karma",25);
    set_skill("blunt",90);	
    set_skill("parry",90);
    set ("max_hp",750);
    set ("hit_points",750);
    set ("time_to_heal",2);
    set ("wealth", ([ "gold":300]) );
    set_natural_weapon(30,18,30);
	set_natural_armor(50,26);
	set ("aim_difficulty",([ "weakest":40,"vascular":50]) );
	set("special_defense", (["magic":40,"none":20]) );
    set ("weight", 400);
    equip_armor(TARMOR"dudey");
    wield_weapon(TWEAPON"huge_staff");
    equip_armor(TARMOR"cowskin_boots");
    equip_armor(TARMOR"golden_ring");
    equip_armor("/d/eastland/saulin_temple/obj/cloth3");
}

