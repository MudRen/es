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
    "guard1" :MOB"guard2",
    "guard2" :MOB"guard2",
    "guard3" :MOB"guard2"
              ]));		
        set( "exits", ([
    "north":MR"tra08",
    "south":MR"tra04"
                ]) );        
         reset();                     
#include <replace_room.h>
}

