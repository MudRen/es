// min5.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("�������");
    set_long(@C_LONG
���������������������һƬ�տ�������ֻ���ؾ���ǽ�ں���
���徲���������������ĺ���������˷����������������Щ���䡣��
�����������磿��������в��ɵ���������  
C_LONG
    );
    set("exits", ([
	"north" : AREA"min6",
	"south" : AREA"min4"
	]) );
    reset();
}

