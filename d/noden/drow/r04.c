#include "iigima.h"
inherit ROOM;
inherit DOORS;

void create()
{
        ::create();
        set_short( "tunnel","ͨ��");
        set_long(
@C_LONG
�����Ǻڰ�������ͨ��������������䶼���ڵص��µ������
���������������£�����ͨ�����ƽ̹������ʯ�ڵĵط����������
֩�룬���ߵ�ͼ����
C_LONG
        );
        set( "light",0 );
        set( "exits", ([

                     "east" : DROW"r05",
                     "west" : DROW"r03",
                     "north": DROW"r01",
        ]) );
        set("objects", ([
                "guard#1": DRO"final_guard",
                "guard#2": DRO"final_guard",
        ]) );
        set( "pre_exit_func", ([
                "north" : "check_guard" ]) );
        reset();

        create_door( "north", "south", ([
                "keyword" : ({ "iron door", "door" }),
                "name" : "iron door",
                "c_name" : "������",
                "status" : "locked",
                "c_desc" : "һ�ȱ���Ĵ����ţ���\n",
                "lock" : "IRON_DOOR"
        ]) );
        reset();
}
int check_guard()
{
        if ( present("guard", this_object() ) ) {
                write("����˵��: �����Ǽ������̳���㲻�ܹ�ȥ����\n");
                return 1; }
        return 0;
}
