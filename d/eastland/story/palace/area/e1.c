#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("�춼����");
	set_long( @LONG
������֮�����춼���Ķ��࣬������ԭ������Ƭ�侫���񽨳ɵģ�������
���ؼѣ�����������ë���ɼ������˵��ڣ��������ߣ�����������գ������߲���
ת��⣻��ƫ�����ʱڣ����һ���Ŵ���������֮����������Ȼ�ռ������ȴ
�淢�Ե�ׯ��¡�أ�������ǧ��
LONG
	);
        set("light",1);
        set("exits" , ([
           "east" : SPALACE"e2",
           "west" : SPALACE"center",
          "north" : SPALACE"n1e1",
          "south" : SPALACE"s1e1",
        ]) );
	reset();
}
