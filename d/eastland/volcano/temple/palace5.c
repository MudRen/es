#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";
inherit DOORS;

void create()
{
	::create();
	set_short( "stairway", "����" );
	set_long(
@LONG
���������ھ����������ȣ�һյյ�����ƻ��������ȵ����ԣ�����������ʲ����
�����ر�С�ģ�����ᷢ��ʲ����ֻ����֪����
LONG
	);
	set( "exits", ([
             "north" : OTEMP"palace7",
             "west" : OTEMP"palace3",
	     "east" : OTEMP"palace8",
	]) );
        create_door("north","south", ([
                    "keyword" : ({"door","diamond door"}),
                    "name" : "diamond door",
                    "c_name" : "��ʯ����",
                    "status" : "locked",
                    "lock" : "DIAMONDKEY",
                    "desc" : "A door made of diamond",
                    "c_desc" : "һ����������ʯ�и���ɵ���"
                    ]) );
         set("light",1);
         reset(); 
}
