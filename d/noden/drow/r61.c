
#include "iigima.h"
inherit ROOM;

void create()
{
       ::create();
       set_short("tuen2","����ʯ��");
       set_long(@C_LONG
�������߳��Ĳ����ᣬ�㵽��ʯ���ľ�ͷ����߸о���
Ϊ���䣬���㲻�����˸�������ǰ���и�ʯ�ף���֪��ͨ��
�δ�����ע�⵽�ڽűߣ��в��ٵ�ëƤ�������ɢ��һ�أ�
�����ƺ���������ټ���
C_LONG);
       set("exits",([
                     "northup":"/d/noden/drow/r62",
                     "southup":"/d/noden/drow/r60"
                    ]));
       set("light",1);
       set("object",([
                      "rat":"/d/noden/drow/mob/m22 "
                   ]));

}
