// rose4.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("���д��");
    set_long(@C_LONG
��������˹�����ǵĳ��д����������Ϸ��ǽ��յĳ��š�����������һ
���ߴ�Ľ����� (building) ������һ��Բ�εĹ㳡 (square) ������·����
���������������������Ƶ��ǣ������Ȼ���б��ֵ���������Ľ��������ǲ�
��˼�顣
C_LONG
    );
    set("exits", (["north" : AREA"rose5"]) );
    set("item_desc", ([
	"building" : @BUILDING
�ⶰ������ۼ�Ľ��������ʾ����ħ��۹���ǿ�󣬻����ĵ�̡����ʵ�
������͸¶���Ŵ������ĸ߶ȷ���뿪������ǰ����һ��ʯ��������������
������Ů���Ķ��ͣ����˴��е��ۻ�  ��˹������ͼ��ݡ���
BUILDING
,
	"square" : @SQUARE
�㳡���������һ��Сʯ������ͷд������������̳�������˵Ƚ����ߴ�
��......���˾�״����ּ������֪����
SQUARE
	]) );
    reset();
}

void init()
{
    add_action("to_enter", "enter");
}

int to_enter(string str)
{
    if (str == "building" || str == "library")
	this_player()->move_player(AREA"lib0", "SNEAK", "");
    else if (str == "square" || str == "altar")
	this_player()->move_player(AREA"altar", "SNEAK", "");
    else
	return notify_fail("�����������?\n");

    return 1;
}
	

