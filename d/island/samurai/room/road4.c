#include <mercury.h>

inherit ROOM;

void create()
{
   ::create();
   set_short( "��ʯС��" );
   set_long(@ANGEL
������һ����ʯС���ϣ�·�����Եı�ԭ���������С�ܶ࣬����·��Ҳ������ʯ
���̳ɣ�����·����ȥ����ͨ���ﱤ��    
ANGEL
   
         );
	set( "light",1);
	set_outside("eastland");		
        set( "exits", ([
      "east" :MR"road2",
      "west" :MR"ca2",
                ]) );
         reset();                     
#include <replace_room.h>
}
