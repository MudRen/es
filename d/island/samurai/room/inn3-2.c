#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "��ʿ�Ŷӳ���" );
   set_long(@ANGEL
��������ʿ�Ŷӳ���ס����Լ��ͨ����������˼����ʿ�ŵĴ�С��
�񣬳���Լ���⣬��������һ�ɲ�׼������¥�ģ�����Լ�޿����ڴ˰�
���ĺú�˼������Ϣ��
ANGEL

   
         );
	set( "light",1);
	set("objects",([
	"ya_shu":MOB"ya_shu"
	]));		
        set( "exits", ([    
    "south" :MR"inn3-1",
                ]) );
                            
         reset();                     
}

