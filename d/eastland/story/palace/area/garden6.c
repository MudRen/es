#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("��������ͤ");
	set_long( @LONG
����ͤ�����㣬ÿһ�㶼�����棬��һ��¥��ȴ�����Ǻϵģ����������ʮ��
�ȡ���ͤͨ���ɺ��񽨳ɣ��۱���ǽ����Ƕ��������͸��죬���ƶ�������������
���˽��ܼⶥ���������������ߣ���Ө���ԣ���ʶ�Ŀ��ͤ���ϻɽ��࣬��ɪ����
��˿��֮������춶�������֪�Ӻζ��������а�������מּ��������˼䣬ȴ������
�����ࡣ
LONG
	);
        set("light",1);
        set("exits" , ([
               "out" : SPALACE"garden5",
        ]) );
        set("no_embattle",1);
        set("objects" , ([
              "king" : SPMOB"king1",
          "gardener" : SPMOB"gardener2",
        ]) );
	reset();
}
