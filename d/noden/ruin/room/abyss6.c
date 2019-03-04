// abyss6.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("��Ԩ");
    set_long(@C_LONG
�����ڴ��һ����Ԩ�ĵײ�������Χ����һƬ�����ɵ���������Ȼ����Ũ
��֮�У���������Լ����������۾����ڿ������㣬�ݷ��������̽ͷ������
����һ��ع���������Ƭ�ڰ�֮�У��ҵ������ƺ�������ĵ���֮����
C_LONG
    );
    set("item_desc", ([
	"bloodstrain" : "һƬ�����Ѫ�����Ա߻��и���̨ (standard)��\n",
	"standard" : "��̨���и�׶ (bodkin)����ͷ�ƺ���Ѫ����\n",
	"bodkin" : "���׵����� (prod) ������϶����ʹ��\n"
	]) );

    set("exits", ([
	"northwest" : AREA"abyss3",
	"northeast" : AREA"abyss4",
	"north" : AREA"abyss5",
	"southwest" : AREA"abyss1",
	"southeast" : AREA"abyss2",
	"south" : AREA"abyss0"
	]) );

    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_prod", "prod");
}

int to_search()
{
    write("���������ң����ֵ��ϻ���һ��ħ���������ƺ���ЩѪ�� (bloodstrain)��\n");
    return 1;
}

int to_prod()
{
    object p;
    p = this_player();

    p->receive_damage(5);
    tell_object(p, "���ü�׶�����Լ�����ָһ�� .... ��ʹ����Ѫ�ˣ� ....\n");
    tell_object(p, "��Ͽ����ָ�ŵ�������˱���������е�Ѫ�ε��˵��� ....\n");

    if (p->query_temp("lilia_abyss") == 6)
    {
	p->set_temp("block_command", 1);
	tell_object(p, "���ϵ�ħ����ͻȻ������â��ǿ���ħ���������ÿһ���񾭣�\n");
    	call_out("activate", 15, p);
    }

    return 1;
}

int activate(object p)
{
    p->delete_temp("block_command");
    p->delete_temp("lilia_abyss");
    tell_object(p, "����ع�����ʱ���㷢����ǰ�ľ����Ѿ�����...\n");
    p->move(AREA"abyss7");
    return 1;
}
