#include <mudlib.h>

inherit CONTAINER;

int left_hole,mid_hole,right_hole;

void create()
{
    ::create();
    set_name("Stone","��а��");
    set_short("��а��");
    set_long(@C_LONG
һ�þ޴����Ȼ�ҿ飬�ҿ�����������С��ͬ��С����(hole)��
������Բ�(insert)����Ү!!
C_LONG
            );
    set("prevent_get",1);
}

