// g4.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("�����Ļ�԰");
    set_long(@C_LONG
��������һ�������Ļ�԰�������������Ӳݺ���̦������Ŀ�����������
ɱ�����գ��ƺ��������ϵ�ѪҺҲ��ҪΪ֮�����������Ӳ����ƺ�������һ��
ʲ�ᶫ���������㿴�������
C_LONG
	    );
    set("exits", ([
	"north" : AREA"g10",
	"east" : AREA"g9",
	"west" : AREA"g5",
	]) );
    reset();
}

void init()
{
    add_action("to_search", "search");
}

int to_search()
{
    write(@DIRE
�ݴ����и�Сƽ̨����ͷ������

		��
	      ��  ��
DIRE
	);
    return 1;
}

