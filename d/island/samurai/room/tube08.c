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
	set("objects",([
	"rat1":MOB"big_rat",
	"rat2":MOB"big_rat"
	             ]));
        set( "exits", ([
                "south":MR"tube07",
                "north" :MR"tube12",
                "east" :MR"tube09"
                
                ]) );
         reset();                     
#include <replace_room.h>
}

