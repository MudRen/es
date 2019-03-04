#include "saulin_monka.c"

void create()
{
	::create();
	set_level(8);
	set_name( "Hwei lin", "����" );
	add( "id", ({ "lin","monk","hwei" }) );
	set_short( "Hwei lin", "����" );
	set_long(
		"Hwei lin is a lower level monk.\n",
		"������һ������ĺ���,������ר�ĵ�ѧ��...\n"
	);
	set( "gender", "male" );
	set( "race", "human" );
	set_perm_stat( "str", 19 );
	set_perm_stat( "dex", 17 );
	set("attack_skill",CLASS"fu_mo");
	set("gonfus/fu_mo",70);
	set_skill( "dodge", 70 );
	set("defense_type","berserk");
	set_natural_armor( 27, 12 );
	set_natural_weapon( 9, 2, 3 );
	set("force_effect",2);
	set( "max_fp", 500 );
	set( "force_points", 500 );
	set( "time_to_heal", 5 );
	set( "wealth/silver", 40 );
	set( "alignment", 200 );
	set( "special_defense", (["all":30]) );
	wield_weapon("/d/eastland/haiwei/obj/staff");
	equip_armor(SAULIN_OBJ"cloth7");
}
