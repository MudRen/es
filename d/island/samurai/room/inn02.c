#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "ǧ��¥ǰͥ" );
   set_long(@ANGEL
������ǧ��¥ǰͥ����·����������һ���������û�п����Ļ�����
Ȼ��û������������֪����һ����һЩ�߹��Ʒ�֣���·�������������
�����������ģ�������������������������Ϊ���ý����̳ɵģ�
ANGEL

   
         );
	set( "light",1);
	set_outside("eastland");		
	set( "objects", ([
	        "guard1":MOB"guard1",
	        "guard2":MOB"guard1",
	        ]) );
        set( "exits", ([
    "south" :MR"inn01",
    "north" :MR"inn03"
                ]) );
                            
         reset();                     
#include <replace_room.h>
}

