#include <mudlib.h>

inherit MONSTER;

void create()
{
	object ob1, ob2;

	::create();
	set_level(8);
	set_name( "Konchi", "空智" );
	add( "id", ({ "bonze" }) );
	set_short( "游方和尚空智" );
	set_long("空智和尚正在四处云游，并且寻找多年前失散的师弟空慧。\n");
	set( "gender", "male" );
	set( "race", "human" );
	set_perm_stat( "int", 15 );
	set_perm_stat( "pie", 17 );
	set_skill( "dodge", 70 );
	set( "natural_armor_class", 30 );
	set( "natural_defense_bonus", 15 );
	set( "natural_weapon_class1", 5 );
	set( "natural_min_damage1", 3 );
	set( "natural_max_damage1", 3 );
	set( "time_to_heal", 5 );
	set( "wealth/silver", 40 );
	set( "alignment", 800 );
	set( "special_defense", (["all":30]) );

	ob1 = new( "/d/eastland/haiwei/obj/staff" );
	ob1->move(this_object());
	wield_weapon(ob1);

	ob2 = new( "/d/eastland/haiwei/obj/pallium" );
	ob2->move(this_object());
	equip_armor(ob2);
}
