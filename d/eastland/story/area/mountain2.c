#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("ɽ��");
	set_long( @LONG
����ɽ��������Զ���ǲ��͵��壬����һĻĻ���̲���ס��������졣���ϰ�
����ͷ��ֻ��������߶ȣ�һĨĨ������ɫ�ı��ӣ���Ҫѹ���������ڶ��������
��Ư����һ����������ǹ���֮��ġ��������ӣ����ɽ֮���ν���һ��Ϫ����
�������ȣ���ˢˢ����������֪�߶����Σ�������һ�ζ����ˣ����⣬����һ��
����Ư��Ϫ���ϡ����㶫���Ǹ����£������ãã��һƬ��Ҳ��֪���ж��
LONG
	);
        set("light",1);
        set( "exit_suppress", ({
	     "down"}) );
	set( "exits", ([ 
            "south" : SAREA"mountain3",
       	    "north" : SAREA"bridge1", 
       	     "west" : SAREA"mountain1",
             "down" : SAREA"vhole1",
        ]) );
        set("goto_palace",1);
        set("can_use_flute",1);
	reset();
}
void init()
{
   add_action("do_search","search");
}
int do_search()
{
    write("�㷢���Ա��и�ֱ��һ�ߵ�С��(hole)ָ������(down)�ķ���\n");
    return 1;
}
