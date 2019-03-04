#include "irc.h"
#define BOARD "/d/std/IRC/irc_board"

inherit ROOM;

void create()
{
    ::create();
    set("light", 1);
    set_short( "Lobby","����" );
    set_long( @LONG
You are in a square shaped, somewhat crude room. There are
four identical archways to the north, west and east directions.
You can hear some noise coming from those.
LONG
	, @C_LONG
����һ�����򵥵ķ��δ���������, ��, ��, ���ĸ��������һ��
��ȫ��ͬ�Ĺ��š������������Լ������˵����������
C_LONG
    );
    set("exits", ([
    	"north"  : IRC"chatroom_1",
    	"east"   : IRC"deck_3",
    	"south"  : IRC"chatroom_4",
    	"west"   : IRC"chatroom_2",
    ]) );
    BOARD->frog();
}
