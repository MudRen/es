#include <mercury.h>

inherit ROOM;

void create()
{
   ::create();
   set_short( "��վ" );
   set_long(@ANGEL
��������ʿ�Ǳ������ǰ��һ����վ������ʿ�Ǳ������ĵ�һ�ߣ���Ӧ��춹۲�
���ʣ����Կ��صı��������࣬������������뿪��ʿ�Ǳ���    
ANGEL
   
         );
	set( "light",1);	
	set_outside("eastland");	
	set("objects",([
	    "guard1" :MOB"guard",
	    "guard2" :MOB"guard",
	    "soldier1" : MOB"soldier",
	    "soldier2" : MOB"soldier"
	    ])
	    );
        set( "exits", ([ 
   "north":MR"cac00",
   "east" :"/d/island/3,7.island"
                ]) );
         reset();                     
}

