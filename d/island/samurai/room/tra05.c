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
    "guard1" :MOB"guard1",
    "guard2" :MOB"guard1",
    "guard3" :MOB"guard1"
              ]));		
        set( "exits", ([
    "north":MR"tra04",
    "west" :MR"tra09"
                ]) );        
         reset();                     
#include <replace_room.h>
}

