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
     "east" : MR"cac02",
     "west" : MR"road4",
                ]) );
         reset();                     
#include <replace_room.h>
}

