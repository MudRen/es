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
    "west"  :MR"cac08",
    "east"  :MR"mar01",    
    "south" :MR"cac10"
                ]) );
                            
         reset();                     
#include <replace_room.h>
}

