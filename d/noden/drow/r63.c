
#include "iigima.h"
inherit ROOM;

void create()
{
       ::create();
       set_short("iceroom","����Ķ�Ѩ");
       set_long(@C_LONG
�������߳��Ľ��ݣ���������һ������Ķ�Ѩ�����ܶ�
����һ�㱡���ı�˪����ʹ��е����죻�㿴����Ѩ�ı���
���ȴ�ʯ�����ε������������ƺ��м�����Ӱ���ǻζ���
C_LONG );
       set("exits",([
                     "north":"/d/noden/drow/r64",
                     "southdown":"/d/noden/drow/r62"
                    ]));
       set("object",([
                      "guard":"/d/noden/drow/mob/m29",
                      "ghost":"/d/noden/drow/mob/m23"
                   ]));
}
