
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(7);
	set_name( "believer", "信徒" );
	add ("id", ({ "dwarf", }) );
	set_short( "Yang's believer", "Yang 的信徒" );
	set_long(
	"   \n",
    "一个安静的信徒,似乎他正期望得到恶神Yang的祝福\n");

    set("alignment", 100 );
    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "个" );
	set_perm_stat( "str", 10 );
	set_perm_stat( "int", 15 );
	set_perm_stat( "kar", 10 );
	set ("wealth", ([ "silver": 200 ]) );
	set_natural_weapon(12,13,18);
	set_natural_armor(33,0);
    set ("weight", 300);
    set_skill("unarmed",50);
    set_skill("dodge",40);
    
	equip_armor(Armour"/cloth03");
}
