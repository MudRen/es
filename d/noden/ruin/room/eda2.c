// eda2.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("���ﲨ���ǹ�������");
    set_long(@C_LONG
���������ﲨ���ǹ��Ĺ��ţ������Ƕ��һ�Ŷ����ˮ��������ԼԼ�ط�
��һЩ�����Ĺ�â��������ҡҡ��׹��ʯ���ͻ�ʯ����ط����Ҳ��Ȼ�ķ���
һ�κܳ���ʱ���ˡ�
C_LONG
    );
    set("exits", ([ "north" : AREA"eda3" ]) );
    reset();
}

