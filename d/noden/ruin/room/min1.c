// min1.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("������");
    set_long(@C_LONG
���������Ĵ���������ʯ�ذ��ϵ����������޴��ʯ����ʯ����ͷ����
����ؿ������ģ��ƺ���Ϊ�˷�ӡĳ�ֿ��µ������õġ��ѵ�������������
��ѹ��ħ�õģ� 
C_LONG
    );
    set("exits", ([
	"south" : AREA"min0",
	"north" : AREA"min2",
	"east" : AREA"min1",
	"west" : AREA"min1"
	]) );
    reset();
}

