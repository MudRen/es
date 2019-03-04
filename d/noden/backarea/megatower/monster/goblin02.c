
#include "../megatower.h"

inherit MONSTER;

void create()
{
	
	::create();
	set_level(3);
	set_name( "fat goblin", "С���" );
	add ("id", ({"goblin", }) );
	set_short( "fat goblin", "���ֵ�С���" );
	set_long(
	"a fat goblin.\n",
    "һֻ���ֵ�С���, �����ֱ۴�׳������\n");

    set( "alignment",-100);
    set( "gender", "male" );
    set( "unit", "��" );
	set_perm_stat( "kar", 4 );
	set_perm_stat( "str", 8 );
	set ("wealth", ([ "silver": 50 ]) );

	set_natural_armor(20,6);
    set_natural_weapon(8,7,12);
    set("aggressive",1);
}
