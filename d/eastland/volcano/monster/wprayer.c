
#include "../oldcat.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name( "prayer", "����" );
	set_short( "����" );
	set_long(
        "һ�����۾�����������ȫ������ߡ�\n");
        set("alignment", 100 );
        set( "gender", "male" );
        set( "race", "dwarf" );
        set( "unit", "��" );
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
