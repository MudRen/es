
#include "../echobomber.h"

inherit SELLER;
inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name( "moorth merchant", "默尔斯商人" );
	add("id",({"merchant",}));
	set_short( "a moorth merchant", "默尔斯商人" );
	set_long(
		"一个来自默尔斯的商人,你可以向他购买物品,只要问他物品(item)"
		",他就会让你看他的货物.\n"
	);
	set("alignment",-300);
	set_perm_stat( "dex", 8 );
	set_perm_stat( "str", 15 );
	set_perm_stat( "int", 15 );
	set_perm_stat( "con", 10 );
	set_perm_stat( "piety", 10);
	set_perm_stat( "karma", 10);	
	set("max_hp", 320);
	set_natural_weapon(18, 18, 25);
	set_natural_armor(55, 15);
	set("hit_points", 320);
	set( "race", "human" );
	set( "gender", "male" );
	// set( "no_attack", 1 );
	set_inventory( ({
		({ Object"/blueapple", 20, 20 }),
	}) );
	set( "inquiry", ([
		"item" : "@@show_menu"
	]) );
    set("chat_chance",10);
    set("chat_output",({
        "默尔斯商人说:我的蓝苹果汁是世界上最好喝的果汁.\n"
        }) );
}

void init()
{
// 	monster::init();
	seller::init();
}
