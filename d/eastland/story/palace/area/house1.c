#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("ˮ������");
	set_long( @LONG
����һ��ͨ��ˮ�����ɵ�С�͵��ã���ȴ���ϳ��ڣ����ŽԱ��������Χ����
�˽�����ӳ��һ��׳���ǳ��������ڳ�����Ǿ���������ⱦ�����������ʣ���
���䴣�����ĸ��޴�������������ۼ������񹤾��£��̻�֮����ѻ��֣�������
յ������ƣ���ת����Ө�׹⣬��ҫ����ͨ�����������֮�£����������֮
�ޣ�����̾Ϊ��ֹ������δ�á�
LONG
	);
        set("light",1);
        set("exits" , ([
           "southeast" : SPALACE"x1",
        ]) );
        set("pre_exit_func",([
           "southeast":"can_pass"]));
        set("objects" , ([
           "northgod" : SPMOB"northgod",
        ]) );
	reset();
}
int can_pass()
{
    if ( !query("cast") ) return 0;
    if ( !this_player()->query_attacker() ) return 0;
    write("�����ѩ�赲�����ȥ·����\n");
    return 1;
}
