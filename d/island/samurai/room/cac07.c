#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "����㳡" );
   set_long(@ANGEL
�������ǰ��һ�����Ĵ�㳡����λ�ÿ�˵�Ǵ˳Ǳ������룬����
����ǰ����ʿѵ�������������ǰ���г���������һֱ����ȥ���Ե���
ʿָ�����ġ�ǧ��¥����
ANGEL

   
         );
	set( "light",1);	
	set_outside("eastland");	
        set( "exits", ([
    "west"  :MR"tra01",
    "east"  :MR"cac08",    
    "south" :MR"cac06"
                ]) );
                            
         reset();                     
#include <replace_room.h>
}

