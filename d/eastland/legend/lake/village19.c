#include "../legend.h"

inherit ROOM;

void create()
{
        ::create();
    set_short("�յ�");
        set_long( 
@LONG
��վ��һƬ�յ��ϣ�����Ұ�ݴ�����Ұ�ݴ�Լ����ͷ�ĸ߶ȣ�ʹ�㿴��������
�ľ���̧ͷһ�����ް���������գ������Ŵغ���һֻֻ����������צ��Ұ�ޣ�
Ұ������ݺݵص����㣬�ƺ�Ҫ������¸���
LONG);
    set( "exits", ([
         "east":LAKE"village10"
    ]) );
    set( "objects", ([
        "vendor":LMONSTER"vendor1",
      "wanderer":LMONSTER"wanderer"
    ]) );    
    ::reset();
}
