#include "irc.h"
 
inherit ROOM;
 
void create()
{
        ::create();
        set("light", 1);
    set_short( "Chatroom","������" );
    set_long( @LONG
You are in yet another squared room. This place is barely
decorated. However, it looks very comfortable.
LONG
    ,@C_LONG
����һ�����򵥵ķ��η���, ��Ȼ�豸��, ������ȴҲ��
����ġ�
C_LONG
    );
    set("exits", ([ "south" : RM+"lobby", ]) );
}
