// lib9.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("��ͼ��ݣ�������");
    set_long(@C_LONG
�����Ǵ�ͼ��ݵ������ң�ʯ�Ƶ����������������ذ�������һ����������
���ڵ�λ�á��⾲�׵������ң���֪����˯�˶��������ˣ��������ڵ�һ��ȴ��
Ȼ�ǳ��ྻ���ɼ�ħ��ŵ۹����������ĸ߳���
C_LONG
    );
    set("exits", ([
	"east" : AREA"lib10",
 	"down" : AREA"lib0"
	]) );
    set("light", 1);
    reset();
}
    
