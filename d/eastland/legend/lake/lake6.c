#include <mudlib.h>
#include "../legend.h"
inherit LAKE"in_lake";

void create()
{
    ::create();
    set_short( "lake6", "����" );
    set_long(@C_LONG
�����ں���,�ŵ�������������ġ�ˮ�塻�����Զ���ǧ�ɸߵ�ˮǽ������ˮ
����¡¡�ؿ�Ҫ����Ķ�Ĥ����, Ю���������ˮ��,���������ȫ�����ʪ��
�� ˮǽ��һЩ�߲ʰ�쵵���������е�׷����ˣ,��ʱ�ν�������,һ��Ҳ������
������,�㲻��������Ҫ����ˮǽȥ��������,ȴ�ƺ��й������赲���㡣
C_LONG
    );
    set( "exit_suppress", ({
      "south","north" }) );
    set( "exits", ([
      "north":LAKE"lake7",
      "east":LAKE"lake3",
      "west":LAKE"lake3",
      "south":LAKE"lake1" 
    ]) );
    reset();
}
