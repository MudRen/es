#include "/d/noden/nodania/nodania.h"

inherit "/d/noden/nodania/monster/knight";
#define BODY_GUARD "/d/noden/nodania/monster/bpalace_guard"

void create()
{
	::create();
	set_level(14);
	set_name("palace guard", "�ʹ�����");
	add( "id", ({ "guard" }) );
	set_short("�ʹ�����");
	set_long(
		"��λ��ʿ��������ŵ��������������������ʮ���Դ˹���Ϊ�١�\n"
	);
	set_perm_stat("str", 20 );
	set_perm_stat("dex", 20 );
	set_perm_stat("con", 20 );
	set_skill("axe", 90);
	set_skill("parry", 90);
	set_skill("block", 90);
	set_natural_armor( 30, 6 );
	set_natural_weapon( 10, 4, 8 );

	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", 600 );
	set( "wealth/silver", 300 );
	set( "special_defense", ([ "all": 25 ]) );
	set( "hit_points", 480 );
	set( "max_hp", 480 );
	set( "war_score", 5000 );
	set( "body_guard",BODY_GUARD );
	wield_weapon("/d/knight/fortress/weapons/battleaxe");
	equip_armor(NODANIA"obj/shield");
	equip_armor(NODANIA"obj/breast_plate");
}
