// min2.c

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
	"south" : AREA"min1",
	"north" : AREA"min3",
	"east" : AREA"min2",
	"west" : AREA"min2"
	]) );
    reset();
}

