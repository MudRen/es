#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("����");
	set_long( @LONG
���������Ѿ�������춼����ˡ����ȵ����˰������ɣ��⻬ϸ�󣬲�Ⱦһ��
ɳ�����ȵ����˵��ξ�ϸ��������֦��Ҷ����׺��ɫ������������Ǯ���룬ܰ����
����Ƣ�������ǻ��ȵ����죬��ʱ����Ȫˮ����о�֮�������������������ȵ���
���ϱ�����ͨ���Ứ԰��С����

LONG
	);
        set("light",1);
        set("exits" , ([
                "west" : SPALACE"x4",
               "north" : SPALACE"garden2",
               "south" : SPALACE"garden3"
        ]) );
	reset();
}
