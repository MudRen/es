#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "�г�" );
   set_long(@ANGEL
���������г���Ϊ�����Ľ��䣬��ǰ������ֱ������������Ե�
�����˺ܶ࣬������һ���õ꣬������ԭ������һ��С�̵굫��Ӫ
�����ѵ��գ�
ANGEL

   
         );
	set( "light",1);		
        set( "exits", ([
    "north":MR"mar09",    
    "west" :MR"mar02",
                ]) );                   
         reset();                     
#include <replace_room.h>
}

