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
    "south"  :MR"tree06",
    "north"  :MR"tree03"
                ]) );
                            
         reset();                     
#include <replace_room.h>
}

