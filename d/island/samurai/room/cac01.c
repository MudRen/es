#include <mercury.h>

inherit ROOM;

void create()
{
   ::create();
   set_short( "��ɪ˹·" );
   set_long(@ANGEL
��������ɪ˹·�ϣ�����һ�����Ĵ�·����·�����ü�Ӳ�Ļ���ʯ���ģ���
��·�����Ը���һ�����ǵﱤһ���Ľ�������������·�����죮    
ANGEL
   
         );
	set( "light",1);
	set_outside("eastland");		
        set( "exits", ([
                "south"  :MR"cac00",
                "north" :MR"cac02",
                ]) );
         reset();                     
#include <replace_room.h>
}

