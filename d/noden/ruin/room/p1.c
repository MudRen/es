// p1.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("��鿲�������������");
    set_long(@C_LONG
ӳ������������һ�����ľ��Ĵ������ذ�����������������ˮ��������
ʯ������ɣ����ܵ�ǽ�ں��컨���������������ıڻ��;��µ�ʯ��Ů����
������������춱��ߵ�̨���ϣ���Χ���������ħ��������������
C_LONG
	    );
    set("exits", ([
	"south" : AREA"p0"
	]));
    set("objects", ([
	"queen" : MOB"queen",
	"emerald" : MOB"emerald"
	]));
    reset();
}


