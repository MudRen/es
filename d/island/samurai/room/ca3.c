#include <mercury.h>

inherit ROOM;

void create()
{
   ::create();
   set_short( "����̨" );
   set_long(@ANGEL
���߽�һ������̨��������ʿ�Ǳ�λ����ߵĵط����������������Ŀ���
��ʿ�Ǳ�������Χ״������˵������Ҫ��Ԥ��ϵͳ���������û���˿��صĻ���
�Ǿ����ǵ��˹�����ǰ����Ҳ���˷��֣�
ANGEL
   
         );
	set( "light",1);
	set_outside("eastland");		
	set( "objects", ([
	        "guard1":MOB"guard2"
	        ]) );
        set( "exits", ([
    "down"  :MR"ca1",
                ]) );
         reset();                     
#include <replace_room.h>
}

