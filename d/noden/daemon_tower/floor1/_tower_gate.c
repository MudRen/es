#include <../tower.h>
void create(object ob)
{
	if (!ob) return;
	ob->set_short("恶魔塔大门");
	ob->set_long( @C_LONG_DESCRIPTION
这里是恶魔塔的大门.
C_LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"south" : "/u/r/ruby/rooms/workroom", 
		"north" : TOWER_F1"room1",
	]) );
	ob->reset();
}
