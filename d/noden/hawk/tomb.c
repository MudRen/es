
#include "hawk.h"

inherit ROOM;
int ring;
void create()
{
        ::create();
        set_short("ĹѨ");
	set("light",1);
        set_long( @LONG_DESCRIPTION
����Ȼ��һ���Ҵ���ɵ�ĹѨ��������ϡ���ó������ĹѨ������Ӧ����
һ���������յ��ˣ���Ϊ���ܵ�ǽ���Է����˸�ʽ�������������н�(sword)
���г�ǹ(lance)���о޸�(axe)������һ������൱�Ӵ�Ķ��ơ��뵽һ��Ӣ
�۾���˲ݲ��������ֻĽ�Ұ�أ��㲻���е������޳���
LONG_DESCRIPTION
        );

set("c_item_desc",([
        "lance":" ����һ����ɫ�ĳ�ǹ��ǹ���ϻ��в���ͼ����\n",
        "axe":" ����һ�Ѻ�ɫ�ľ޸������ֻ�о��˲��а취�õĶ���\n",
        "shield":"�������������Ǿ��ˣ����������˴���ǲ������⡣\n",
        "sword":" ����һ������һ������ľ޽���\n",
                ]) );
	set( "exits", ([
		"out":"/d/noden/2,5.noden" ]) );
        reset();
}//end of creat

void init()
{
        add_action("to_search","search");
        add_action("to_pray","pray");
}

int to_search(string str)
{
        object obj;
        if ((str != "shield" && str != "����") || ring == 0)
                return notify_fail( "���Ŭ����������ȥ������û��ɶ�ջ�\n");
        tell_object(this_player(),
                "��... ���ҵ���һö����ɫ�Ľ��ӡ�\n");
	obj = new(OBJ"ring");
        obj->move(this_object());
        this_player()->set_temp("find_ring",1);
        ring = 0;
        return 1;
}

int to_pray()
{
        if (this_player()->query_temp("smore_box") == 5)
        {
                tell_room(environment(this_player()),
                        this_player()->query("c_name") +
                        "�ϵĹ���Ĺǰ��ϣ�������ܹ���Ϣ��\n"
                ,this_player() );
                tell_object(this_player(),@LONG
���ݷ𿴵�Ĺ��Ʈ��һ�ɵ����İ����û���һλӢ�����ʿ����Ӱ��
��������΢Ц��Ȼ���Ʈ�������ʧ�����ˡ�
��������մ���һ����׳���º͵�������лл�㣬��ʿ��������߰���
˿�Ҷ�������ľ�����
LONG
                );
                this_player()->set_temp("smore_box",6);
       }

        return 1;
}

void reset()
{
        ::reset();
        ring = 1;
}
