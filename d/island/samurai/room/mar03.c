#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "�г�������" );
   set_long(@ANGEL
�����г���������ס�ĵط�����Ȼ��һ�����ң��������ϴ��»���Ǭ
������ǽ�Ǳ߷���һ�������ܣ���ǽ�����Ǽ�¼�����µ�������Σ�
ANGEL

   
         );
	set( "light",1);
	set( "objects",([
    "guard1":MOB"market_guard",
    "guard2":MOB"market_guard"
            ]));			
        set( "exits", ([
   "south" :MR"mar02"
                ]) );                   
         reset();                     
#include <replace_room.h>
}

