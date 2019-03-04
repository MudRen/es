// min7.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("�������");
    set_long(@C_LONG
����������������������ĺ�����Ȼ������ͣ���㲻�ɵý���
�����ϵ��·���������ǽ�����и����� (niche)����ͷƮ����һ������
�ĳ�ɫˮ����ˮ������ͷ�ƺ���Щ��ֵ�ͼ����
C_LONG
    );
    set("exits", ([
	"south" : AREA"min6"
	]) );
    set("light", 1);
    set("item_desc", ([
	"niche" : @NICHE
����һ���ɴ���ʯ�����ƶ��ɵ����裬�����ǰ���и�С���ӣ�����д
��������;�ĸ���! �԰���˹֮ӡ�ϵ�����! ����
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

    if (p->query(QUESTNAME) > 2)
    {
        return notify_fail("���Ѿ�����һ���ˣ���ʡʡ�����ɡ�\n");
    }

    p->set(QUESTNAME, 2);
    tell_object(p, "��С������ذѰ���˹֮ӡ�����ħ���ֵ�ıʼ����\n");
    return 1;
}

int to_pray()
{
    object p;
    p = this_player();
    tell_object(p, "���������ˮ��������Щʲ�����? ...\n");
    p->delete_temp("lilia_pass");
    p->move(AREA"rose4");
    return 1;
}
