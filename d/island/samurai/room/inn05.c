#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "��ʿ�Ÿ��ӳ���" );
   set_long(@ANGEL
����������ʿ�Ÿ��ӳ��ǿ���ס������˵�ǿ�����ʿ�Ǳ��еĵڶ���
�����������ס��ȴ�ǳ������أ�ֻ��һ�Ŵ������Σ�û���������ŵ�
�Ҿߣ�ǽ�����ǹ����˸�л״����Щ�����ǿ���\��\ʱ\��\�õ��Ľ���������
�Ա������ǿ��շŷ��ߵ����ӣ�
ANGEL

   
         );
	set( "light",1);
	set("objects",([
	"si_ka":MOB"si_ka"
	]));		
        set( "exits", ([
    "south"  :MR"inn04",    
                ]) );
                            
         reset();                     
}

