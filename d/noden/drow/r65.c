
#include "iigima.h"
inherit ROOM;

void create()
{
       ::create();
       set_short("palace1","�񹬲��");
       set_long(@C_LONG
���������Ǵ��񹬵������Ķ�����һ�����Ĺ���
ͨ��������������������һ�Ű�����ͭ��ʯ̳������
���˲��ٵı�����ʯ̳���䲢��ʱ��һ�ɰ����������ң�
��Ȼ����Ѿã�����������˿�����������Ӱ�죬�Է�����
�¡�
C_LONG );
       set("exits",([
                     "east":"/d/noden/drow/r66"
                    ]));
       set("light",1);
}
