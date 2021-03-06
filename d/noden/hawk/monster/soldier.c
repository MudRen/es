// /d/noden/hawk/monster/scout.c

#include <mudlib.h>
#include "../hawk.h"
inherit MONSTER;

void create()
{
        ::create();
        set_level(8);
        set_name("hawkman soldier", "鸟人族士兵");
        add( "id", ({"hawkman", "soldier"}) );
        set_short("鸟人族士兵");
        set_long(
                "鸟人族中地位最低，武艺最差的士兵。\n"
        );
        set( "gender", "male" );
        set( "race", "hawkman" );
        set( "alignment", 100 );
        set_natural_armor( 20, 5 );
        set_perm_stat( "str", 12 );
        set_perm_stat( "dex", 8 );
        set_skill( "longblade", 70 );
        set_skill( "parry", 40 );
        set_skill( "dodge", 30 );
        set( "wealth/silver", 200 );

	wield_weapon( WEAPON"stone_sword" );
	equip_armor( ARMOR"leather_hauberk" );
}
