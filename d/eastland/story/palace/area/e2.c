#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("���ڳ���");
	set_long( @LONG
�����ǵ��ڳ��ȡ��ȵ������̵أ����˵��ξ�ϸ�����ÿ����Ƕ��ȭ��ҹ����
������һ���������ߣ���ʱ�����׹⣬��ҫ������ͨ�����������춼�������
�ף��������£�����ׯ�ϣ������ޱȣ����������ϡ����������졣
LONG
	);
        set("light",1);
        set("exits" , ([
               "west" : SPALACE"e1",
              "north" : SPALACE"x2",
          "southeast" : SPALACE"x4",
        ]) );
	reset();
}
