// min3.c

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
	"south" : AREA"min2",
	"north" : AREA"min4",
	"east" : AREA"min3",
	"west" : AREA"min3"
	]) );
    reset();
}

