#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("���ڳ���");
	set_long( @LONG
�����ǵ��ڳ��ȡ��ȵ������̵أ����˵��ξ�ϸ�����ÿ����Ƕ��ȭ��ҹ����
������һ���������ߣ���ʱ�����׹⣬��ҫ������ͨ�����ϱ����춼�������
�ף��������£�����ׯ�ϣ������ޱȣ������ǳ��ȵ����졣
LONG
	);
        set("light",1);
        set("exits" , ([
           "southwest" : SPALACE"x1",
               "south" : SPALACE"n1",
        ]) );
	reset();
}
