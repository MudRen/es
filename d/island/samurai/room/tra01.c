#include <mercury.h>
inherit DOORS;
inherit ROOM;

void create()
{
   ::create();
   set_short( "��ʿѵ�������" );
   set_long(@ANGEL
�������ǰ����ʿѵ��������ڣ���������������ʿ��Ա������ȥ��
�ط������еȼ�����ʿ������ÿ�쵽�����Ͽμ��д����գ������ڴ���Ũ
Ũ�ĺ��������˽���ʿ�ǿ��������࣮��
ANGEL

   
         );
	set( "light",1);		
	set( "objects", ([
	        "guard1":MOB"guard1",
	        "guard2":MOB"guard1",
	        ]) );
        set( "exits", ([
    "east" :MR"cac07",
    "west" :MR"tra02"
                ]) );
      create_door("west","east",([
                  "keyword" : ({"door","wooden door"}),
                  "status"  : "closed",
                  "name"    : "Wooden Door",
                  "c_name"  : "ľ��",
                  "c_desc"  : "һ��ľͷ������\n"
                  ]) );
                            
         reset();                     
}

