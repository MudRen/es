#include <mercury.h>

inherit ROOM;

void create()
{
   ::create();
   set_short( "����ˮ��" );
   set_long(@ANGEL
������һ������ˮ������Ȼ���ڵ��£�������ȴ�Ǻ����£����㲻��
�����Ƶĸо��������㷢�����������Ǭ���ģ��ƺ����˾�ס�����森    
ANGEL
   
         );
         
	set( "light",0);
        set( "exits", ([
                "west":MR"tube08",
                "east" :MR"tube10"
                ]) );
         reset();                     
#include <replace_room.h>
}

