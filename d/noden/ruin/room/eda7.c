// eda7.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("����");
    set_long(@C_LONG
�㱻���͵�һ������������ҵ���������һ����ɱ�����գ�����
�е��ܲ����ڡ�������ǽ�����и����� (niche)����ͷƮ����һ������
�Ļ�ɫˮ����ˮ������ͷ�ƺ���Щ��ֵ�ͼ����
C_LONG
    );
    set("light", 1);
    set("item_desc", ([
	"niche" : @NICHE
����һ���ɴ���ʯ�����ƶ��ɵ����裬�����ǰ���и�С���ӣ�����д
��������;�ĸ���! �Բ�����֮ӡ�ϵ�����! ����
NICHE
	]) );
    reset();
}

void init()
{
    add_action("to_sketch", "sketch");
    add_action("to_pray", "pray");
}

int to_sketch()
{
    object p;
    p = this_player();

    if (p->query(QUESTNAME) > 3)
    {
        return notify_fail("���Ѿ�����һ���ˣ���ʡʡ�����ɡ�\n");
    }

    p->set(QUESTNAME, 3);
    tell_object(p, "��С������ذѲ�����֮ӡ�����ħ���ֵ�ıʼ����\n");
    return 1;
}

int to_pray()
{
    object p;
    p = this_player();
    tell_object(p, "���������ˮ��������Щʲ�����? ...\n");
    p->move(AREA"rose4");
    return 1;
}
