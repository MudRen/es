#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "ǧ��¥��¥" );
   set_long(@ANGEL
��������ǧ��¥��¥����ǧ��¥��ߵĵط���ͬʱҲ����ʿ�Ŷӳ�Լ�޵�ס
������Ҳ������ĵط������������Ҳ����κ�һ���������ƺ�Լ�޶��������
¥�������൱�����ţ������л�Ʈ��һ�ɺ�̴ľ��������
ANGEL

   
         );
	set( "light",1);		
        set( "exits", ([
    "down"  :MR"inn2-6",    
    "north" :MR"inn3-2",
                ]) );
                            
         reset();                     
#include <replace_room.h>
}

