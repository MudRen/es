#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "ǧ��¥��¥" );
   set_long(@ANGEL
��������ǧ��¥��¥������Ĺ����һ¥������������ͬ��ֻ��ͨ����խ��
��࣬��˵����Ϊ��ֹ���˴������ֶ���Ƶģ��ذ�ĳ��ý��׷���������ľ��
���ɣ�ֻҪ����һ�����¥���䷢��������һ���ᱻ�ڶ�¥��������ʿ��������
�����л�Ʈ��һ�ɺ�̴ľ��������
ANGEL

   
         );
	set( "light",1);		
        set( "exits", ([
    "south"  :MR"inn2-1",    
    "east" :MR"inn2-3",
    "north":MR"inn2-4"
                ]) );
                            
         reset();                     
#include <replace_room.h>
}

