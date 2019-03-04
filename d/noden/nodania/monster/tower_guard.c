#include "../nodania.h"

inherit "/d/noden/nodania/monster/knight";

object weap, armor;

void create()
{
	::create();
	set_level(13);
	set_name("tower guard", "����" );
	add( "id", ({ "guard" }) );
	set_short( "������¥������" );
	set_long(
		"�������������¥�ϵ��ξ�����������������Щƣ�롣\n"
	);
   set( "alignment", 500 );
	set_perm_stat("str",16);
	set_perm_stat("dex",15);
	set_skill("parry", 50);

	set( "race", "human" );
	set( "gender", "male" );
	set( "natural_armor_class", 40 );
	set( "war_score", 500 );

	wield_weapon("/d/knight/fortress/weapons/longsword");
	equip_armor("/d/knight/fortress/armors/chainmail");
}
