#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
    set_short("Alley", "����");
	set_long( @LONG_DESCRIPTION
This is the inner hall of scholar's guild. .
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
��������ī���Ķ�¥, �������������ļ��鷿, ��Ի����÷��������������
��ī���Լ������ա���
C_LONG_DESCRIPTION
	);
	set( "light", 1 );
	set( "exits", ([ 
		"down"  : "/d/scholar/scholar/scholar_guild",
                "north" : "/d/scholar/scholar/gonfu_room2",
		"east" : "/d/scholar/scholar/ponder_room",
		"south"  : "/d/scholar/scholar/train_room",
                "up" : "/d/scholar/scholar/embattle_room",
		"west" : "/d/scholar/scholar/scholar_inner", ]) );
        set("objects",([
                "stone":"/d/scholar/scholar/stone1"]));
      	reset();
}
