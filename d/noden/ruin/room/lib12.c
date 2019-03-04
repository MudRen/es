// lib12.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("��ͼ��ݣ�չ����");
    set_long(@C_LONG
�ⷿ����տ�������ֻ��һ�Ŵ�ʯ̨����ͷ������һ������������ˮ����
ʯ̨��ǰ���и�С���ӣ�����д��������˵�е�����ˮ���򣬿���ָ�����ߵ���
���ĵط�ȥ����
C_LONG
    );
    set("exits", (["west" : AREA"lib11"]));
    set("light", 1);
    reset();
}

void init()
{
    add_action("to_touch", "touch");
}

int to_touch(string str)
{
    object p;
    p = this_player();

    if (str == "ball" || str == "crystal ball" || str == "ˮ����")
    {
	if (p->query(QUESTNAME) >= 4)
	{
            tell_object(p, "ˮ�����Ӧ�����Ϸ�ӡ������������һ����â�������㣬�㷢���Լ������͵���ĵط�!\n");
            p->move_player(AREA"g0", ({"%s��һ������Ĺ�â��������!\n", "%s������һ����â���������\n"}), "" );
        }
	else
	    tell_object(p, "��������ˮ���򣬵����ƺ�ʲ�����鶼û�з�����\n");

	return 1;
    }
    else
        return notify_fail("������ʲ��? ��������ǲ��õ���ΪŶ ....\n");
}

