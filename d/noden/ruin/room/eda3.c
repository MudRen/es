// eda3.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("���ﲨ���ǹ�������");
    set_long(@C_LONG
�߽����ﲨ���ǹ��������ֻ��ʯ��������ɢ����һ�أ�Ŀ����������
һƬ�ư������ľ��������������и�ƽ̨�������п�Сͭ�� (plate)���ƺ�
�������֡�
C_LONG
    );
    set("item_desc", ([
	"plate" : "ͭ���Ͽ������������ӣ����ﲨ���Ǵ��ˡ�\n"
	]) );
    set("exits", ([ "north" : AREA"eda4" ]) );
    reset();
}

