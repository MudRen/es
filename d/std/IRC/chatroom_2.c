#include "irc.h"
 
inherit ROOM;
 
void create()
{
	::create();
	set("light", 1);
    set_short( "Chatroom","谈天室" );
    set_long( @LONG
You are in yet another squared room. This place is barely
decorated. However, it looks very comfortable.
LONG
	, @C_LONG
这是一间陈设简单的方形房间, 虽然设备简单, 看起来却也满
舒服的。
C_LONG
    );
    set("exits", ([ "east" : IRC"lobby", ]) );
}
