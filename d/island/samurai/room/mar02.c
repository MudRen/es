#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "�г�" );
   set_long(@ANGEL
������������Ǿۼ��ڴ�������Ʒ���������ʿ�Ǳ��ڵ��г�����˵
������ʿ���������ֵĵط���������������Ʒȴ�ٵĿ��������������һ
Щ���õĶ�����Ȱ�㻹�Ǳ�������ɣ�
ANGEL

   
         );
	set( "light",1);		
        set( "exits", ([
    "north":MR"mar03",    
    "west" :MR"mar01",
    "east" :MR"mar08",
    "south":MR"mar04"
                ]) );                   
         reset();                     
#include <replace_room.h>
}

