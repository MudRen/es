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
    "east"  :MR"cac09",
    "west"  :MR"cac07",    
    "south" :MR"cac05",
    "north" :MR"inn01"
                ]) );
                            
         reset();                     
#include <replace_room.h>
}

