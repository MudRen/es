#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("���ڳ���");
	set_long( @LONG
�����ǵ��ڳ��ȡ��ȵ������̵أ����˵��ξ�ϸ�������Ƕ��һ��ȭ��ҹ����
������һ���������ߣ���Ө���ԣ���ҫ������ͨ�����������춼��������ף�
�������£�����ׯ�ϣ������ޱȡ��ȵ��������������졣
LONG
	);
        set("light",1);
        set("exits" , ([
           "northwest" : SPALACE"x3",
               "north" : SPALACE"s1",
        ]) );
	reset();
}
