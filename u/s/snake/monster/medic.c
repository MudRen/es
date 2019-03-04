#include <mudlib.h>

inherit "/std/seller";
inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "Medic Wang", "��ҩʦ" );
	add( "id", ({ "medic", "wang" }) );
	set_short( "Medic Wang", "��ҩʦ" );
	set_long(
		"Medic Wang has just come back from a long trip in the mountains\n"
		"for gathering rare herbs and record the places they grow.\n",
		"��ҩʦ�մ���ɽ�в�ҩ������������ҽ�߹��ϵĲ�ҩȨ��������\n"
		"�������ҩ�������ĵص㶼�������ֵġ��������������һЩ��\n"
		"ҩ������þ߻�һЩ������ҩ�ģ������йز�ҩ(herb)�����顣\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat("str",30);
	set_perm_stat( "int", 30 );
	set_perm_stat( "kar", 30 );
	set_perm_stat( "dex", 30 );
	set_skill( "dodge", 100 );
	set_skill( "dagger", 100 );
	set_skill( "anatomlogy", 100 );
	set( "aiming_loc", "weakest" );
	set( "max_hp", 600 );
	set( "hit_points", 600 );
	set_natural_armor( 110, 50 );
	set_natural_weapon( 50, 25, 36 );
	set( "special_defense", ([ "all": 50,"none":60]) );
	set( "aim_difficulty",([ "weakest":25,"vascular":30 ]) );
	set( "alignment", 1500 );
	set( "inquiry", ([ "herb":"@@show_menu"]) );
	set_inventory( ({
		({ "/obj/bowl", 20, 20 }),
		({ "/d/healer/reagent/yellow_mushroom", 30, 30 }),
		({ "/d/healer/reagent/swamp_berry", 30, 30 }),
		({ "/d/healer/reagent/ginseng", 5, 5 }),
	}) );
}
