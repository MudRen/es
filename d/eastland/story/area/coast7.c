#include "../story.h"

inherit ROOM;
int be_pick=0;
void create()
{
        ::create();
	set_short("����");
	set_long(@LONG
��������һ���ȴ����������������Ǹ߼�ͷ����ާ��ֲ������������Ҫʹ
����赹�ڵأ����������ֲ�����С�棬��ס�ض������ȫ�������ѹ��Ѽ���
�����Ҹ������ĵط���Ϣһ�£��ټ����ߣ���ù�һ�㡣վ�������ʱ������
��Ұ�޵Ľ������������������Ѽ������Ǹ�Σ�յĵط���
LONG
	);
	set("exits", ([ 
           "north" : SAREA"coast3"
        ]) );
        set("objects", ([
           "patient" : SMOB"patient1"
        ]) );
	reset();
}
void init()
{
    add_action("do_search","search");
    add_action("do_pick","pick_up_some");
}
int do_search(string arg)
{
    if ( be_pick ) return 0;
    write("�㷢�ּ�����ֵĳ��٣��������пյģ���������Լ񼸸�(pick_up_some)��Ϊ���ܣ�\n");
    return 1;
}
int do_pick(string arg)
{
    object straw;
    if ( be_pick ) return 0;
    be_pick=1;
    write("�����ó����������������ܣ���\n");
    straw=new(SITEM"straw");
    straw->move(this_object());
    call_out("back",300);
    return 1;
}
void back()
{
   be_pick=0;
}