#include "/d/noden/nodania/nodania.h"

inherit "/d/noden/nodania/monster/knight";
#define BODY_GUARD "/d/noden/nodania/monster/bsoldier.c"

void create()
{
	::create();
	set_level(6);
	set_name("Nodania soldier", "诺达尼亚士兵");
	add( "id", ({ "soldier" }) );
	set_short("诺达尼亚士兵");
	set_long(
		"你看到一个诺达尼亚城得正规军士兵，誓死保卫他的家园。\n"
	);
	set_perm_stat("str", 10 );
	set_skill("polearm", 40);
	set_skill("parry", 30);

	set( "race", "human" );
	set( "gender", "male" );
	set( "natural_armor_class", 20 );
	set( "war_score", 100 );
	set( "alignment", 300 );
	set( "body_guard",BODY_GUARD);
	wield_weapon(NODANIA"obj/pike");
	equip_armor(NODANIA"obj/chainvest");
}
