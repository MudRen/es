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
	set( "objects",([
    "merchant":MOB"fruit_merchant"
            ]));			
        set( "exits", ([
    "north":MR"mar02",    
    "east" :MR"mar07",
    "south":MR"mar05"
                ]) );                   
         reset();                     
#include <replace_room.h>
}

