// lib5.c

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
	"west" : AREA"lib4",
	"east" : AREA"lib6"
	]) );
    set("item_desc", (["wall" : "ǽ�ϻ���һ�ѽ����ʷ�����׾�ӡ�\n"]) );
    set("light", 1);
    reset();
}


