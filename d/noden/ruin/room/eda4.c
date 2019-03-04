// eda4.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("���ﲨ���ǹ��������");
    set_long(@C_LONG
����������Ȼ�Ѿ��ٻ��ˣ��������������� (throne) ȴ��Ȼ�������
����һ���ؽ�̻Ի͡���������ҷ�����һ��С�ţ�Ӧ����ͨ��������Ϣ�ҵ�
ͨ�����Ϸ���ͨ��ͨ����ղ�����������
C_LONG
    );
    set("item_desc", ([
        "throne" : "�����ϵ����һֻ���۹� (ogre)�������������ˡ�\n",
	"ogre" : "����۹ֵ��۾��ƺ���ĳ�ְ�ť (button)��\n"
        ]) );
    set("exits", ([ 
	"south" : AREA"eda3",
	"west" : AREA"eda5",
	"east" : AREA"eda6"
	 ]) );
    reset();
}

void init()
{
    add_action("to_push", "push");
}

int to_push(string s)
{
    object p;
    p = this_player();

    if (s == "button")
    {
 	write("�㰴��һ�¶��۹ֵ��۾��������������ֵ��˻�����\n\n");
        write("���Ȼ���֣����۹��ƺ����ݺݵص�����! ����һ����ѣ!\n\n");
	p->set_temp("block_command", 1);
        call_out("recover", 15, p);
	return 1;
    }
    
    return notify_fail("���밴ʲ��?\n");
}

int recover(object p)
{
    p->set_temp("block_command", 0);
    tell_object(p, "����ع�����ʱ���㷢����ǰ�ľ����Ѿ�����...\n");
    p->move(AREA"eda7");
    return 1;
}

