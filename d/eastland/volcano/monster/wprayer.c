
#include "../oldcat.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name( "prayer", "祈祷者" );
	set_short( "祈祷者" );
	set_long(
        "一个正聚精会神祈祷保佑全族的祈祷者。\n");
        set("alignment", 100 );
        set( "gender", "male" );
        set( "race", "dwarf" );
        set( "unit", "个" );
	set_perm_stat( "str", 15 );
	set_perm_stat( "int", 15 );
	set_perm_stat( "kar", 10 );
	set ("wealth", ([ "gold": 20 ]) );
	set_natural_weapon(7,7,10);
	set_natural_armor(20,10);
    set ("weight", 300);
    set_skill("unarmed",70);
    set_skill("dodge",50);

    equip_armor(OARMOR"armband1");
    equip_armor(OARMOR"cloth1");
}
