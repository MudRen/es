#include "../legend.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("����ص׶�Ѩ");
    set_long(@LONG
�����Ѿ����ڵ��³�����ʮ����ĵط���ǽ���ϵġ���ޱ������������࣬����
�и�������ֹ֣�������Ҳ�в���ֲ��β�͡���ޱ������һ����Щ������ޱ��һ
������������ө�⣬�������ȵ���ɫ�ģ���Щ����СС�Ļ���ɢ������ķ��㡣��ǰ
��С�컨����һֻ�޿���״��͸�����ﴫ�����ӡ������ӡ���ϸ΢���죬�����ڶ���
ʾ��һ�㡣
LONG
    );
    set("light",1);
    set("exits",([
            "westup":LAKE"swamp_d2",
    ]) );
    set("objects",([
      "shapeshifter":LMONSTER"shapeshifter1"
    ]) );  
    ::reset();
}

