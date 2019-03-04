
#include "../layuter.h"

inherit ROOM;

void create()
{
	::create();
	set_short("龙穴");
	set_long( @C_LONG_DESCRIPTION
当你进入此洞穴时你发现此处是一个火山熔洞，四周都是奇怪的火红色岩石，并且
有时有一些奇怪的岩石结晶，当其被火光映照之时，会反射出绚丽的光线，加上原有的
火红构成一副优美的景色，令你几乎忘了身在何处。山洞到了此处居然有分叉，颇令人
不知何去何从。
C_LONG_DESCRIPTION
	);
	set( "light", 0 );
	set( "exits", ([
	    "east" : Lcave"cave2",
		"northwest" : Lcave"cave4",
		"southwest" : Lcave"cave5"
	]) );
	reset();
#include <replace_room.h>
}
