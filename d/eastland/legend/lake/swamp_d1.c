#include "../legend.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("����ص׶�Ѩ");
    set_long(@LONG
�������������һ����ֵĶ�Ѩ��û�������ڱǵĸ�������������صġ��ǣ�
Ҳû���׶��˵���������ޣ��෴�ģ�����Ŀ������µ����˻���û��һ��ë��
�����죬�����������ʵ�������������һ��ǳǳ�ĵ���Ȫˮ���������������Ĺ�����
����ԼԼ���Կ��������Ϸ�����һ��ͨ������֪��ͨ��ʲ��ط���
LONG
    );
    set("exits",([
            "eastdown":LAKE"swamp_d2",
            "south":LAKE"swamp_d3",
            "up":LAKE"swamp8",
    ]) );
    set("objects",([
          "icetoad#1":LMONSTER"icetoad",
          "icetoad#2":LMONSTER"icetoad",
          "icetoad#3":LMONSTER"icetoad",
    ]) );
    ::reset();
}

