#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "�õ�" );
   set_long(@ANGEL
������һ�䲻���۵��õ꣬�谵�ĵƹ���ϾɵļҾߣ����㻳��
���ֵ������������ס����
ANGEL

   
         );
	set( "light",1);		
	set( "objects",([
	"fan":MOB"fan"
	]));
        set( "exits", ([
    "up":MR"mar10",    
    "south" :MR"mar08"
                ]) );                   
         reset();                     
#include <replace_room.h>
}

