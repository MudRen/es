#include "iigima.h"

inherit ROOM;

void create()
{

        ::create();
        set_short( "stone floor","����ʯ��");
        set_long(

@C_LONG
������һ���߳���ʯ�ף��������£��㿴����ʯ�׵ľ�ͷ��ǽ��΢��
�Ļ�ѻ�����˸�������Ǻ����Ϩ���ˣ�����ʪ�����ģ����в�����̦��
��ҪС�Ĳ��У�ǧ��𻬵��ˡ�
C_LONG
        );
        set( "light",1 );
        set( "exits", ([           
                     "southeast": DROW"r39",
                    "north":DROW"r28"
        ]) );
}
