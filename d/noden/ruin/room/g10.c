// g10.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("�����Ļ�԰");
    set_long(@C_LONG
��������һ�������Ļ�԰�������������Ӳݺ���̦������Ŀ�����������
ɱ�����գ��ƺ��������ϵ�ѪҺҲ��ҪΪ֮�����������Ӳ���մ���˰߰�Ѫ��
��������������������ˡ�
C_LONG
	    );
    set("exits", ([
	"north" : AREA"g10",
	"east" : AREA"g9",
	"west" : AREA"g3",
	]) );
    set("objects", (["deathknight" : MOB"deathknight"]));
    reset();
}


	    
