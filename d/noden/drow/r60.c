
#include "iigima.h"
inherit ROOM;

void create()
{
       ::create();
       set_short("tune2","����ʯ��");
       set_long(@C_LONG
������б��ʯ��бб����ǰ���꣬��֪����ͷ�ںδ���
ʯǽ�ϣ�ÿ�����������һ����ѣ��㲻����˶���ʧ�˷�
�����ھ��ó��棬û��˿�����죬·�ľ�ͷ�ݷ��Ҳ���
�Ƶģ�����ҪС�ĵ�ǰ����
C_LONG );
       set("exits",([
                     "northdown":"/d/noden/drow/r61",
                     "southup":"/d/noden/drow/r70",
                    ]));
       set("light",1);
       set("object",([
                      "ghost":"/d/noden/drow/mob/m21",
                   ]));

}
