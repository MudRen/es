
#include "iigima.h"
inherit ROOM;

void create()
{
       ::create();
       set_short("garden","����ͥ��԰");
       set_long(@C_LONG
�����Լ�����ͬ��С�Ļ�԰�����˸�ʽ���������컨
�ܣ��㿴��������һ��С�������滹�и�С����Ҳ���˸���
��ͬ��ֲ��ƺ���������ߴ�ɨ��ͥ԰�ľ�ͷ��һ���ţ�
�������ý����ģ������ǲ��ܴ��ˡ�
C_LONG );
       set("exits",([
                     "southeast":"/d/noden/drow/r68"
                    ]));
       set("light",1);
       set("object",([
                      "linna":"/d/noden/drow/mob/m28"
                   ]));
}
