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
    "west" :MR"cac09",
    "east" :MR"mar02"
                ]) );                   
         reset();                     
#include <replace_room.h>
}

