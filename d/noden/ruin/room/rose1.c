// rose1.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();

    set_short("����");
    set_long(@C_LONG
��������һ���ƾɵķ��棬����ɢ�������ܵ�ʯ����ʯ�顣��������С��
���ϱ��������졣��ע�⵽�ڲ�Զ�������������и�СӪ�� (camp) ������͸
����Щ΢�Ĺ������ƺ������˾�ס�����ӡ�������˭��ס�������ط��أ�
C_LONG
    );
    set("exits", ([
	"north" : AREA"rose2",
	"south" : AREA"rose0",
	"camp" : AREA"camp"
	]) );

    reset();
}
	
