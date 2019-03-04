#include <irc.h>
#define BOARD "/d/std/IRC/irc_board"
 
inherit ROOM;
 
void create()
{
	::create();
	set("light", 1);
    set_short( "Lobby","����" );
    set_long(
@LONG
You are in a square shaped, somewhat crude room. There are two
identical metallic doors to the north and east direction. The post
office is to the west. You can hear some noise coming from the south.
 
LONG
@C_LONG
����һ�����򵥵ķ��δ���. �ڱ�, �������������һ����ȫ��
ͬ�Ľ�����. �������ʾ�. �Ϸ��ķ�����Լ��������.
 
C_LONG
    );
    set("exits", ([
    "north"  : RM+"chatroom_1",
    "east"   : RM+"chatroom_3",
    "south"  : RM+"pub",
    "west"   : RM+"irc_post"
                ]) );
    BOARD->frog();
 
}
 