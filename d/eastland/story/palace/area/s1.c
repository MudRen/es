#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("�춼����ϲ�");
	set_long( @LONG
������֮�����춼�����ϲ࣬������ԭ������Ƭ�侫���񽨳ɵģ�������
�ѣ�����������ë���ɼ������˵��ڣ��������ߣ�����������գ������߲�Ѥ����
�⣻��ƫ�����ʻ棬��ڵ�¥������֮����������Ȼ�ռ������ȴ�淢�Ե�ׯ
��¡�أ�������ǧ�����ɶ���ϱ��ǵ�ȡ�
LONG
	);
        set("light",1);
        set("exits" , ([
           "east" : SPALACE"s1e1",
           "west" : SPALACE"s1w1",
          "north" : SPALACE"center",
          "south" : SPALACE"s2",
        ]) );
	reset();
}
