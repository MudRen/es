#include "iigima.h"
inherit ROOM;
inherit DOORS;

void create()
{
        ::create();
        set_short( "gate","����֮��");
        set_long(
@C_LONG
�����Ǻڰ������Ľ��أ�ǰ�����������������죬�Լ�������
������ó���ȫ������׼������Ϊ����֪���Ŀֲ�������ʱ�ᵽ����
C_LONG
        );

        set( "exits", ([
                   "northeast": DROW"r37",        
                   "south": DROW"r04",
        ]) );
        create_door( "south", "north", ([
                "keyword" : ({ "iron door", "door" }),
                "name" : "iron door",
                "c_name" : "������",
                "c_desc" : "һ������������š�\n",
                "status" : "locked",
                "lock" : "IRON_DOOR"
        ]) );         
}
