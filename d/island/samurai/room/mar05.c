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
    "merchant":MOB"vage_merchant"
            ]));			
        set( "exits", ([
    "north":MR"mar04",    
    "east" :MR"mar06"
                ]) );                   
         reset();                     
#include <replace_room.h>
}

