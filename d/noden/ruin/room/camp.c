// camp.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();

    set_short("�����ڲ�");
    set_long(@C_LONG
������������ڲ�������Ķ�������һյ�谵���͵ƣ�ǽ�Ƕ����������
����������������˲����Ǹ���ѧ�ʵ��ˣ������Ѿ�ס������ܾ��ˡ���ע��
����ǽ�Ϲ���һ����ֵı��� (rune) ��Ƭ��
C_LONG
    );
    set("exits", (["out" : AREA"rose1"]) );
    set("light", 1);
    set("objects", (["explorer" : MOB"deltazeus"]) );

    reset();
}
 
