// lib1.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("��ͼ��ݣ�����");
    set_long(@C_LONG
���������һ�������������ϣ�����ʯ�̳ɵ��ߵ��򶫷����졣������һ
�������ħ���ڣ���������ؿ��������ڵ����Ρ����ȵ�ǽ�ڲ�֪����ʲ�ᶫ��
������ģ���ҫ�������Ĺ�â��
C_LONG
    );
    set("exits", ([
	"west" : AREA"lib0",
	"east" : AREA"lib2"
	]) );
    set("light", 1);
    reset();
}


