#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "�õ��¥" );
   set_long(@ANGEL
�������õ��¥��һ��С���䣬�����ڶ�¥�����չ����룬�ɹ��
һ¥�ö��ˣ�����������һЩ���䣮��
ANGEL

   
         );
	set( "light",1);
	set( "objects",([
    "nakoruru":MOB"nakoruru",
    "eagle"   :MOB"eagle"
           ]));			
        set( "exits", ([
    "down":MR"mar09",    
                ]) );                   
         reset();                     
}

