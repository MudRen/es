#include "/d/noden/nodania/nodania.h"
#define BODY_GUARD "/d/noden/nodania/monster/bgate_guard.c"
inherit "/d/noden/nodania/monster/knight";

void create()
{
	::create();
	set_level(10);
	set_name("gate guard", "卫兵");
	add( "id", ({ "guard" }) );
	set_short("看守王宫的卫兵");
	set_long(
		"这个卫兵正守卫著城门，他看起来十分以此工作为荣。\n"
	);
	set_perm_stat("str", 13 );
	set_skill("longblade", 70);
	set_skill("parry", 50);
	
	set( "race", "human" );
	set( "gender", "male" );
	set( "natural_armor_class", 40 );
        set( "war_score",1000);
	set( "body_guard",BODY_GUARD);
	wield_weapon("/d/knight/fortress/weapons/longsword");
	equip_armor("/d/knight/fortress/armors/chainmail");
}
