#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("�춼������");
	set_long( @LONG
������֮�����춼���Ķ����࣬������ԭ������Ƭ�侫���񽨳ɵģ�����
�ؼѣ�����������ë���ɼ������˵��ڣ��������ߣ�����������գ������߲�Ѥ��
�ӹ⣻��ƫ�����ʻ棬��ڵ�¥������֮����������Ȼ�ռ������ȴ�淢�Ե�
ׯ��¡�أ�������ǧ�����ɶ��
LONG
	);
        set("light",1);
        set("exits" , ([
           "west" : SPALACE"n1",
          "south" : SPALACE"e1",
        ]) );
	reset();
}