#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";
inherit DOORS;

void create()
{
	::create();
	set_short( "С��Ů�޹�" );
	set_long(
@LONG
�����������Ķ���Ů�����ĵ��޹���������������һƬ���������㣬���ɫ
�ı��ӣ���ɫ�Ĵ���ǽ���ǵ�������ɫ����ױ̨�Ϸ���һЩС��Ʒ��һ����
�Ӻ�һֻ�廨�롣
LONG
	);
	set( "exits", ([
	     "south" : OTEMP"palace5",
	]) );
        create_door("south","north", ([
                    "keyword" : ({"door","diamond door"}),
                    "name" : "diamond door",
                    "c_name" : "��ʯ����",
                    "status" : "locked",
                    "lock" : "DIAMONDKEY",
                    "desc" : "A door made of diamond",
                    "c_desc" : "һ����������ʯ�и���ɵ���"
                    ]) );
         set("light",1);
         set("objects", ([
             "princess":OMONSTER"princess",
             ]) );
         reset(); 
}
