// tower2.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("ħ��ʦ������һ��");
    set_long(@C_LONG
������ħ��ʦ���ĵ�һ�㣬�ذ��ϻ���������������������ģ��ƺ�����
������ĳ�ֿ��µ������õġ������г����˸�ʬ����ζ�����ֱ�����������
������跨�뿪����ط������²���֮����Ҳ����һ��ʬ���ˡ�
C_LONG
	    );
    set("exits", ([
	"north" : AREA"tower2",
	"east" : AREA"tower3",
	"south" : AREA"tower3",
	"west" : AREA"tower2"
	]));
    reset();
}

