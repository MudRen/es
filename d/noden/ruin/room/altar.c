// altar.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("������̳�㳡");
    set_long(@C_LONG
��������һ�����������˷�ë�ĵط������ϵ����������صķ��ţ��ݷ���
ĳ��ħ�������ġ��㳡��������һ����̳ (altar)���㷢�ּ�̳����һ��Ʈ��
�ڿ��е����� (statue) ɢ������ů�Ĺ�â���㲻�����߽�������
C_LONG
    );
    set("exits", (["east" : AREA"rose4"]) );
    set("light", 1);
    set("item_desc", ([
	"altar" : @ALTAR 
һ��ɢ�����߲ʹ�â�ļ�̳����֪����ʲ�����ɵ�? ��̳�Ͽ�������С��
д�������������ϵ�����������Ů��ʥ����;������ĵ�ף�ɵ�ָ����ԸŮ
���ٹⳣ����٭���ҡ���
ALTAR
,
	"statue" : @STATUE
����һ���̵�����������Ů������Ȼ������ò����ʮ������������ü
��֮������͸��һ�����ϡ�
STATUE
       ]) );
    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_pray", "pray");
    add_action("to_touch", "touch");
}

int to_search(string s)
{
    object p;
    p = this_player();

    if (s == "altar")
    	if (p->query(QUESTNAME) >= 1)
    	{
	    tell_object(p, "��̳���и�С��â�� (hexagram mark)���㲻���������� (touch)��\n");
	    return 1;
        }
    return notify_fail("������ʲ��?\n");
}

int to_touch(string s)
{
    object p;
    p = this_player();

    if (s == "mark" || s == "hexagram" || s == "hexagram mark")
	if (p->query(QUESTNAME) >= 1)
	{
	    tell_object(p, "��â���ϴ���һ�󲨶�����������ʶ������ع���ʱ�����Լ������͵�һ���µĵط�!\n");
	    p->move_player(AREA"min0", "SNEAK", "");
	    return 1;
        }

    return notify_fail("������ʲ��?\n");
}

int to_pray()
{
    object p;
    p = this_player();
    tell_object(p, "�������������������Щʲ�����? ...\n");
    p->move("/d/noden/nodania/sealroom");
    return 1;
}

