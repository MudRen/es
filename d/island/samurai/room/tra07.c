#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "��ʿѵ����" );
   set_long(@ANGEL
������������ʿѵ�����ڣ����ܰ��˺ü��������õ�ľͷ�����м�����
ϰ�õ�ľ������һ�ԣ�һ��ŨŨ�ĺ���ζ�̼�����ı��ӡ�
ANGEL

   
         );
	set( "light",1);
	set( "objects",([
    "soldier1" :MOB"soldier",
    "soldier2" :MOB"soldier",
    "soldier3" :MOB"soldier"
              ]));		
        set( "exits", ([
    "south":MR"tra02",
                ]) );        
         reset();                     
#include <replace_room.h>
}

