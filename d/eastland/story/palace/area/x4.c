#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("���ڳ���");
	set_long( @LONG
�����ǵ��ڳ��ȣ������������������졣�ȵ������̵أ����˵��ξ�ϸ�����
ÿ����Ƕ��ȭ��ҹ���飬����һ���������ߣ���ʱ�����׹⣬��ҫ������ͨ������
�Ӷ������ڵ��ǻ��ȣ�����ͨ���Ứ԰��
LONG
	);
        set("light",1);
        set("exits" , ([
                "east" : SPALACE"garden1",
           "northwest" : SPALACE"e2",
        ]) );
	reset();
}
