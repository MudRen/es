#include "../nodania.h"

inherit "/d/noden/nodania/monster/knight";

void create()
{
	::create();
	set_level(17);
	set_name("body guard", "护卫骑士");
	add( "id", ({ "guard" }) );
	set_short("国王的贴身护卫");
	set_long(
		"这个骑士是国王耶拉曼的贴身护卫，也是皇家骑士团中挑选出来的菁英。\n"
	);
	set_perm_stat("str", 25);
	set_perm_stat("int", 23);
	set_perm_stat("dex", 25);
	set_perm_stat("kar", 25);
	set_skill("polearm", 100);
	set_skill("parry", 100);
	set( "hit_points", 550 );
	set( "max_hp", 550 );
	set( "alignment", 700 );

	set( "gender", "male" );
	set( "race", "human" );
	set_natural_armor( 50, 20 );
	set_natural_weapon( 20, 10, 20 );
	set( "class", "knight" );
	set( "special_defense", ([ "all": 25 ]) );
	set( "war_score", 20000 );

	wield_weapon( NODANIA"obj/halberd" );

	equip_armor( NODANIA"obj/steel_plate" );
	equip_armor( NODANIA"obj/steel_helmet" );
}
