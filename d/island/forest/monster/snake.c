#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(3);
    set_name("Big Snake","������");
    add("id",({"snake"}) );
    set_short("������");
    set_long(@LONG
һβ�����˵Ĵ��������̾���ɽ���Ե���֦�ϣ�������ĵ�������
���ϵĶ������������ţ�������������Ƶ�!!
LONG
    );
    set("unit","β");
    set("no_attack",1);
}