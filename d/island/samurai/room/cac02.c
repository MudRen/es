#include <mercury.h>

inherit ROOM;

void create()
{
   ::create();
   set_short( "ʮ��·��" );
   set_long(@ANGEL
������һ��ʮ��·���ϣ����Ҹ���һ��С·ͨ��ﱤ�����ϱ�������ɪ˹·��
����Կ�����������һ���ߴ�����
ANGEL
   
         );
	set( "light",1);
	set_outside("eastland");		
	set( "objects", ([
	        "guard1":MOB"guard",
	        "guard2":MOB"guard",
	        ]) );
        set( "exits", ([
    "west"  :MR"road2",
    "east"  :MR"road1",
    "south" :MR"cac01",
    "north" :MR"cac03"
                ]) );
         reset();                     
#include <replace_room.h>
}

