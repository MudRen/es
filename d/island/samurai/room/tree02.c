#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "�ּ�С��" );
   set_long(@ANGEL
������ӣ�������е�С���ϣ���·�����Զ���ʢ����ӣ������Ʈ���ӣ����
����ǰ������������һ�������ľ�ɫ��Ҳ��֪�������������ֵģ���Щӣ������
Ȼ�ܱ����ļ�������������������һ�ֶ��������ذɣ�
ANGEL

   
         );
	set_outside("eastland");		
        set( "exits", ([
    "east"  :MR"tree01",
    "north"  :MR"tree06"
                ]) );
                            
         reset();                     
#include <replace_room.h>
}

