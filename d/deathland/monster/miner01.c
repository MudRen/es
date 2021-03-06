
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(12);
	seteuid(getuid());
	set_name( "Dwarf Miner", "矮人矿工" );
	add ("id", ({"dwarf", "miner"}) );
	set_short( "a dwarf miner", "矮人矿工" );
	set_long(
	"a working dwarf miner.\n",
	"一个辛苦开矿的矮人矿工.他的一生大部份的时间都是在矿坑里渡过\n"
	);

    set("alignment",330);
    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "个" );
	set_perm_stat( "dex", 14 );
	set_perm_stat( "str", 20 );
	set_perm_stat( "int", 7 );
	set_perm_stat( "con", 20 );
	set_perm_stat( "piety", 15);
	set_perm_stat( "karma", 10);
	set_skill("thrusting",60);
	set_skill("dodge",78);
	set ("max_hp", 250);
	set ("hit_points", 250);
	set ("wealth", ([ "gold": 10 ]) );
	set_natural_weapon(18,10,17);
	set_natural_armor(60,7);
    set ("weight", 400);    
    set ("chat_chance", 7);
	set ("chat_output", ({
//             "Miner says: There are some strange monsters in the mine\n",
	    "矿工说:有一些奇怪的怪物存在於矿坑的深处.\n",
	    }) );
	wield_weapon(Weapon"/pick01.c");
}
