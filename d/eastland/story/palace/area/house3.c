#include "../../story.h"

inherit ROOM;

void create()
{
        object goldgod;
        ::create();
	set_short("С�͵���");
	set_long( @LONG
��������Ƭ�ƽ��Ƴɵģ���ȴ���������⣬���ŽԱ��������Χ���˴˽�����
ӳ��׳���ǳ��������ڳ�����Ǿ����������ɺ�����ƣ��������ʣ��Ľ��䴣��
���ĸ��޴�������������ۼ������񹤾��£��̻�֮����ѻ��֣�������յ������
�ƣ���ת����Ө�׹⣬��ҫ����ͨ��������֮�£����������֮�ޣ�����̾Ϊ
��ֹ��ֱ��δ�á�
LONG
	);
        set("light",1);
        set("exits" , ([
           "northeast" : SPALACE"x3",
        ]) );
        set("no_embattle",1);
        goldgod=new(SPMOB"goldgod");
        goldgod->move(this_object());
        set("objects" , ([
          "westgod" : SPMOB"westgod",
        ]) );
	reset();
}
int clean_up()
{  return 0; }
