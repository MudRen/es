
#include "../megatower.h"

inherit MONSTER;

void create()
{
	
	::create();
	set_level(1);
	set_name( "little goblin", "С���" );
	add ("id", ({"goblin", }) );
	set_short( "little goblin", "С���" );
	set_long(
	"a little goblin.\n",
    "һֻСС��С���\n");

    set( "alignment",-100);
    set( "gender", "male" );
    set( "unit", "��" );
	set_perm_stat( "kar", 2 );
	set ("wealth", ([ "silver": 10 ]) );

	set_natural_armor(4,1);
    set("aggressive",1);
}
