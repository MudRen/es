#include "../legend.h"

inherit ROOM;

void create()
{
        ::create();
    set_short("����·");
        set_long( 
@LONG
�����������ĵ�·�ϣ�ӭ����������һ��ŨŨ���ȳ�ζ���ڵ��ϣ��ݺύ��
��Ѫˮ��Ǭ��С�ӣ�һ���Ų�Ӭ��������춸��õ������ϣ���ʱ�������˵�������
�ް���������գ������Ŵغ���һֻֻ����������צ��Ұ�ޣ�Ұ������ݺݵص���
�㣬���������˵���������ɣ������ɣ��ҵ�ʳ�������������һ�Ѻ���ͬ�߶�
��Ұ�ݣ���·���ϡ��������ꡣ
LONG);
    set( "exits", ([
         "south":LAKE"village10",
        "north":LAKE"village18"
    ]) );
    set("objects",([
        "boy#1":LMONSTER"boy",
        "boy#2":LMONSTER"boy",
        "girl#1":LMONSTER"girl",
    ]) );
    ::reset();
}
