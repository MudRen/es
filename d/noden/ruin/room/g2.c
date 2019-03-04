// g2.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("�ưܵ�С��");
    set_long(@C_LONG
���ߵĲݴ����һ���ưܵ�С����ͷ�ƺ��и����� (niche)��
һƬ���������У��ƺ�������С·ͨ��������������������������
���ܵĿ����ƺ����������ݷ���ĳ�ֲ����Ԥ�ס�
C_LONG
    );
    set("light", 1);
    set("item_desc", ([
	"niche" : @NICHE
����һ���ɴ���ʯ�����ƶ��ɵ����裬�����ǰ���и�С���ӣ�����д
��������;�ĸ���! �����ܵĶ������������ϵ�����! ����
NICHE
	]) );
    set("exits", ([
	"north" : AREA"g3",
	"west" : AREA"g1"
	]) );
    set("objects", (["ghost" : MOB"ghost"]));
    reset();
}

void init()
{
    add_action("to_pray", "pray");
}

int to_pray()
{
    object p;
    p = this_player();
    tell_object(p, "�������������Щʲ�����? ...\n");
    p->move(AREA"rose4");
    return 1;
}
