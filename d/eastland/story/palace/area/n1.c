#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("�춼����");
	set_long( @LONG
������֮�����춼���ı��࣬������ԭ������Ƭ�侫���񽨳ɵģ�������
�ѣ�����������ë���ɼ������˵��ڣ��������ߣ�����������գ������߲�Ѥ����
�⣻��ƫ�����ʻ棬��ڵ�¥������֮����������Ȼ�ռ������ȴ�淢�Ե�ׯ
��¡�أ�������ǧ�����ɶ��
LONG
	);
        set("light",1);
        set("exits" , ([
           "east" : SPALACE"n1e1",
           "west" : SPALACE"n1w1",
          "north" : SPALACE"n2",
          "south" : SPALACE"center",
        ]) );
	reset();
}
