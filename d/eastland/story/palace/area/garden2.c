#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("����");
	set_long( @LONG
������������򼺾��ǵ��˾�ͷ��̧ͷһ����ǰ��һ�Ʒ�����ն���������һ
����ɫƥ���������ȱ�ڴ���к��������ٵ��γɡ������ˣ������Ƽ��ܴ�������
����֮�ƣ�ǰ�����ʮ�ɲŽ���ƽ�����ȵ����˵��ξ�ϸ������һ��Լ��ĶԲ��
�������ذ������������������Ǳ�֦�����������������̲����ۣ�������Ӿ������
ʱ�š�����һ�����ţ����ξ�ϸ���ɶ��칤��ͨ��ˮ�����ɣ�������ã�ҫ������
��������һ���ķ���¥�󣬸߳�ˮ��Լ���ߣ��������죬����ׯ�ϡ�

LONG
	);
        set("light",1);
        set("exits" , ([
             "south" : SPALACE"garden1",
            "bridge" : SPALACE"bridge1",
        ]) );
        set("pre_exit_func",([
            "bridge":"can_pass"]));
	reset();
}
int can_pass()
{
   if ( this_player()->query("palace_war") ) return 1;
   return 0;
}
