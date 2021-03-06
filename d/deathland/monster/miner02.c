
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	object ob1,ob2;
	::create();
	set_level(15);
	//seteuid(getuid());
	set_name( "Dwarf miner guard", "矮人矿工守卫" );
	add ("id", ({"dwarf", "guard"}) );
	set_short( "a dwarf miner", "矮人矿工守卫" );
	set_long(
	"a guard is protecting miners.\n",
	"一个矮人矿工守卫.由於矮人矿坑里充满著危险,皇室特别从皇家守卫中\n"
	"挑出菁英,来保护矿工的安全.\n"
	);

    set("alignment",400);
    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "个" );
	set_perm_stat( "dex", 18 );
	set_perm_stat( "str", 23 );
	set_perm_stat( "int", 17 );
	set_perm_stat( "con", 20 );
	set_perm_stat( "piety", 15);
	set_perm_stat( "karma", 17);
	set_skill("thrusting",70);
	set_skill("parry",70);
	set ("max_hp", 470);
	set ("hit_points", 470);
	set ("wealth", ([ "gold": 10 ]) );
	set_natural_weapon(19,10,25);
	set_natural_armor(35,15);
    set ("weight", 400);    
    set ("chat_chance", 5);
	set ("chat_output", ({
//             "Guard says: Dont attack the miners\n",
	    "矿工守卫说:不要攻击矿工.\n",
	    }) );
	wield_weapon(Weapon"/lance01");
	equip_armor(Armour"/plate05");
}
