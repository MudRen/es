
#include "iigima.h"
inherit ROOM;

void create()
{
       ::create();
       set_short("palace3","�񹬲��");
       set_long(@C_LONG
һ���ɡ�ľ����̵ľ޴����ռ�����������䣬�����
�����Ǵ��񹬵��ҵ��˵���Ǵ�����ʱ�����Դ˵�Ϊ����
��������Ʒ���鼮�ĵط��������ڰ������ǻ�����λΰ���
��ʿ���������Ĺʾӣ����˴��񹬣�Ҳ�����Ǵ���ǰ�����
���ڴ˴������ñ��档
C_LONG );
       set("exits",([
                     "north":"/d/noden/drow/r68",
                     "west":"/d/noden/drow/r66"
                    ]));
       set("light",1);
}
