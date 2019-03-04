// abyss5.c

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
	"candle" : "һ���Ұ׵İ�ɫ���򣬵�����������Եõ�������\n"
	]) );
    set("exits", ([
	"southwest" : AREA"abyss3",
	"southeast" : AREA"abyss4",
	"south" : AREA"abyss6"
	]) );

    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_light", "light");
}

int to_search()
{
    write("���������ң����ֵ��ϲ��������� (candle)��\n");
    return 1;
}

int to_light(string s)
{
    object p;
    int count;

    if (s != "candle")
	return notify_fail("�������ʲ�᣿\n");

    p = this_player();
    tell_object(p, "����������� ... ������ȴ�Զ�Ϩ���� ...\n");

    if (p->query_temp("lilia_abyss"))
    	count = p->query_temp("lilia_abyss");
    else
	count = 0;

    if (count < 6)
        count++;

    p->set_temp("lilia_abyss", count);
    return 1;
} 
