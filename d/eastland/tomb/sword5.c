#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("石室");
	set_long( 
@C_LONG_DESCRIPTION
你进入了一个小小的石室，与外面比起来，这儿真是小的微不足道。四周空无一物，只
有一根蜡烛孤独地点在墙边。
C_LONG_DESCRIPTION
	);
	set( "light", 1);
	set( "exits", ([ 
		"north" : TOMB"/sword4",  ]) );
	set( "objects", ([
		"swordman" : MOB"/sword_slave" ]) );
	reset();	
#include <replace_room.h>
}

