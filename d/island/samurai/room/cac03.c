#include <mercury.h>
inherit DOORS;
inherit ROOM;

void create()
{
   ::create();
   set_short( "դ��" );
   set_long(@ANGEL
�������ǰ��һ�������դ�ţ���Ҫ������ʿ�Ǳ��ؾ�֮�ؿ�������
ʿ�Ǳ���ͨ����Ŧ��
ANGEL

   
         );
	set( "light",1);
	set_outside("eastland");		
	set( "objects", ([
	        "guard1":MOB"guard1",
	        "guard2":MOB"guard1",
	        ]) );
        set( "exits", ([
    "south" :MR"cac02",
    "north" :MR"cac04"
                ]) );
      create_door("north","south",([
                  "keyword" : ({"door","iron door"}),
                  "status"  : "closed",
                  "name"    : "Iron Door",
                  "c_name"  : "��դ��",
                  "c_desc"  : "һ��������դ��\n"
                  ]) );
                            
         reset();                     
}

