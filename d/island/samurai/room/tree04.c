#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "�ּ�С��" );
   set_long(@ANGEL
������ӣ�������е�С���ϣ���·�����Զ���ʢ����ӣ������Ʈ���ӣ����
����ǰ������������һ�������ľ�ɫ��Ҳ��֪�������������ֵģ���Щӣ������
Ȼ�ܱ����ļ�������������������һ�ֶ��������ذɣ�������Ϊ���Գ���̫����
��������������С�����յ㣮
ANGEL

   
         );
	set_outside("eastland");
	set("objects",([
	"killer":MOB"killer"
	]));		
        set( "exits", ([
    "south"  :MR"tree03"
                ]) );
                            
         reset();                     
}

