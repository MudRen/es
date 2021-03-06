#include <../zeus.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(17);
	set_name("paradise guard", "守卫骑士");
	add( "id", ({ "guard" }) );
	set_short("酒境守卫");
	set_long(@AA
这个守卫是段家特地从巨人国所请来的武士，虽然在他的武\功\不是顶尖的
但是忠诚的信念却是无人可比的．他的眼光紧紧地盯著铁门，不让任何一
个人偷偷溜进去．
AA
);
	set_perm_stat("str", 25);
	set_perm_stat("int", 20);
	set_perm_stat("dex", 22);
	set_perm_stat("kar", 20);
	set_skill("blunt", 100);
	set_skill("parry", 100);
	set( "hit_points", 500 );
	set( "max_hp", 500 );
	set( "alignment", 100 );

	set( "gender", "male" );
	set( "race", "troll" );
	set_natural_armor( 50, 20 );
	set_natural_weapon( 20, 10, 20 );
	set( "class", "knight" );
	set( "special_defense", ([ "all": 25 ]) );

	wield_weapon( ZOBJ"/black_staff" );

	equip_armor( ZOBJ"/black_plate" );
	equip_armor( ZOBJ"/black_leggings" );
}