#include <mercury.h>
inherit DOORS;
inherit ROOM;

void create()
{
   ::create();
   set_short( "��ʿѵ����" );
   set_long(@ANGEL
������������ʿѵ�����ڣ����ܰ��˺ü��������õ�ľͷ�����м�����
ϰ�õ�ľ������һ�ԣ�һ��ŨŨ�ĺ���ζ�̼�����ı��ӣ�ǽ�Ϲ���һ����
��(picture)����
ANGEL

   
         );
	set( "light",1);		
        set( "exits", ([
    "east" :MR"tra01",
    "west" :MR"tra04",
    "south":MR"tra03",
    "north":MR"tra07"
                ]) );
      create_door("east","west",([
                  "keyword" : ({"door","wooden door"}),
                  "status"  : "closed",
                  "name"    : "Wooden Door",
                  "c_name"  : "ľ��",
                  "c_desc"  : "һ��ľͷ������\n"
                  ]) );
     set("c_item_desc",(["picture":@AAA
     ����Կ������������Խ�����ë��д��:
     
     ��ʿ֮��������ֹ��
     
AAA
]));                            
         reset();                     
}

