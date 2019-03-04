
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	
	::create();
	set_level(16);
	set_name( "Dwarf warrior", "����սʿ" );
	add ("id", ({ "warrior", "dwarf", }) );
	set_short( "a dwarf warrior", "����սʿ" );
	set_long(
	"   \n",
    "һ������սʿ,��������ʨ����.\n");

    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "��" );
	set_perm_stat( "str", 20 );
	set ("wealth", ([ "silver": 200 ]) );
	set_natural_weapon(10,10,20);
	set_natural_armor(30,37);
    set ("weight", 300);
    set ("aim_difficulty",([ "critical":30,"vascular":25]) );
    set ("chat_chance", 15);
    set("chat_output",({
// "Warrior strikes you.\n",
        "��սʿ�Ӷ������ĸ�ͷ,һ����������������.\n"
        }));
    set_skill("axe",90);
    set_skill("parry",80);
    set("special_defense",(["all":20,"none":5]));
	wield_weapon(Weapon"/axe01"); 
    equip_armor(Armour"/plate02");
    equip_armor(Armour"/shield02");
    equip_armor(Armour"/boots02");

}
