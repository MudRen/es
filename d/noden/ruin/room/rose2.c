// rose2.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();

    set_short("����");
    set_long(@C_LONG
��������һ���ƾɵķ��棬����ɢ�������ܵ�ʯ����ʯ�顣��������С��
���ϱ��������죬�����Ĳ�Զ���ƺ�����ˮ����������ط�������ʪ��ȴ��һ
����̦Ҳû�У��㲻�ɵô��˸����䡣
C_LONG
    );
    set("exits", ([
	"north" : AREA"rose3",
	"south" : AREA"rose1"]) );

    reset();
}
