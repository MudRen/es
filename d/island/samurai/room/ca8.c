#include <mercury.h>

inherit ROOM;

void create()
{
   ::create();
   set_short( "��ǽ" );
   set_long(@ANGEL
������һ����ʿ�Ǳ�����Χ��ǽ���յ㣬���λ�������ǳ��ŵ��Ϸ�����
�˿��Թ������ŵĵ��ˣ�����Ϊ��ս�Ե���������Ҳ�����ر�������
ANGEL
   
         );
	set( "light",1);
	set_outside("eastland");
	set( "objects", ([
	     "ekars" :MOB"ekars",
	     "guard1" :MOB"guard2",
	     "guard2" :MOB"guard2",
	          ]));
        set( "exits", ([
    "west" :MR"ca7",
                ]) );
         reset();                     
#include <replace_room.h>
}

