#include "iigima.h"

//inherit DOORS;
inherit ROOM;

void create()
{

        ::create();
        set_short( "perotice's room","̴�㷿");
        set_long(
        @C_LONG
������һ���������᷿�����ܴ��������̴�㣬������������һ
���Ǹ���Ӽ�����ˡ�������һ��ͭ������һЩ�۲ʣ�������Ů����
���������ǽ�Ϲ���һ���������裬�Ա߻�����һ�����ӣ���ͷ��һ��
�������ţ��ұ�ǽ�������һ�����л��ƵĶ��ơ�
C_LONG
        );

        set( "light",1 );
        set( "exits", ([
                     "out": DROW"r25",
        ]) );
        set("objects", ([
             "perotice": DRO"knight",
        ]) );
	reset();
}

int clean_up() { return 0; }
           
