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
    "merchant":MOB"fish_merchant"
            ]));			
        set( "exits", ([
    "west":MR"mar05",    
    "north" :MR"mar07"
                ]) );                   
         reset();                     
#include <replace_room.h>
}

