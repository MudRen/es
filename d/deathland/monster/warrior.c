
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	
	::create();
	set_level(16);
	set_name( "Dwarf warrior", "矮人战士" );
	add ("id", ({ "warrior", "dwarf", }) );
	set_short( "a dwarf warrior", "矮人战士" );
	set_long(
	"   \n",
    "一个矮人战士,负责看守著狮鹫兽.\n");

    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "个" );
	set_perm_stat( "str", 20 );
	set ("wealth", ([ "silver": 200 ]) );
	set_natural_weapon(10,10,20);
	set_natural_armor(30,37);
    set ("weight", 300);
    set ("aim_difficulty",([ "critical":30,"vascular":25]) );
    set ("chat_chance", 15);
    set("chat_output",({
// "Warrior strikes you.\n",
        "这战士挥动著他的斧头,一副威风懔懔的样子.\n"
        }));
    set_skill("axe",90);
    set_skill("parry",80);
    set("special_defense",(["all":20,"none":5]));
	wield_weapon(Weapon"/axe01"); 
    equip_armor(Armour"/plate02");
    equip_armor(Armour"/shield02");
    equip_armor(Armour"/boots02");

}
