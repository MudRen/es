// g7.c

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
	"north" : AREA"g9",
	"east" : AREA"g8",
	"west" : AREA"g10",
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

