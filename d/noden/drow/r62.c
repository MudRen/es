#include "iigima.h"
inherit ROOM;

void create()
{
       ::create();
       set_short("coldtune","�����ʯ��");
       set_long(@C_LONG
�����ĳ���ʯ�ײ�֪���쵽�δ�����������ı����Բ�
�л�ѣ����������������˸е����£��������Խ��Խ���
�����������̲�ס���˸�������
C_LONG );
       set("exits",([
                     "northup":"/d/noden/drow/r63",
                     "southdown":"/d/noden/drow/r61"
                    ]));
       set("light",1);
}
