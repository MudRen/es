// lib2.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("��ͼ��ݣ�����");
    set_long(@C_LONG
���������һ�������������ϣ�����ʯ�̳ɵ��ߵ������������졣����  
��ǽ���ϻ��������ֵ�ͼ�����ƺ���ĳ��ͿѼ�����ȵ�ǽ�ڲ�֪����ʲ�ᶫ��
������ģ���ҫ�������Ĺ�â��
C_LONG
    );
    set("exits", ([
	"west" : AREA"lib1",
	"east" : AREA"lib3"
	]) );
    set("item_desc", (["wall" : "ǽ�ϻ���һ���ߣ��ʷ�����׾�ӡ�\n"]) );
    set("light", 1);
    reset();
}


