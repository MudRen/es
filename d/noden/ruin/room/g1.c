// g1.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("�����Ļ�԰");
    set_long(@C_LONG
��������һ�������Ļ�԰�������������Ӳݺ���̦���������������ص�ʪ
������Ȼ�ٲ����Ǵ̱ǵ�ùζ����ش̼������������Ӳ����ƺ�������һ��
С��ͨ���������Ϸ����������Ƕ��Ŀ�����������һЩ�������롣
C_LONG
	    );
    set("exits", ([
	"south" : AREA"g0",
	"east" : AREA"g2"
	]) );
    reset();
}
