#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("���ڳ���");
	set_long( @LONG
�����ǵ��ڳ��ȣ���������������Ѿ��Ǿ�ͷ�ˡ��ȵ������̵أ����˵��ξ�
ϸ�����ÿ����Ƕ��ȭ��ҹ���飬����һ���������ߣ���ʱ�����׹⣬��ҫ������
ͨ����
LONG
	);
        set("light",1);
        set("exits" , ([
           "south" : SPALACE"e2",
        ]) );
	reset();
}
