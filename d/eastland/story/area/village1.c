#include "../story.h"
inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("���");
	set_long(@LONG
��������һ���������ס�Ĵ�ׯ���ϣ�������һ���ŵ�С�ݡ�������������
��һ��Ƭ������Եø������������֣�����һ����Ȼ��ס���������ڵ�·����ֲ
����������������ϵĹ�ʵƽʱ��������ʳ�����ʵ�е�Һ֭Ҳ������������Ϊ
����ˮԴ����������ûʲ���Ŀռ䣬С�����Ƕ����ܵ������ߵĲ�ԭȥ����
���������Ƕ�����Ϊ�ǣ��������ﱻ�˷��֡�
LONG
	);
	set("light",1);
	set("exits", ([ 
                "east" : SAREA"house1",
                "west" : SAREA"house2",
               "south" : SAREA"village2",
           "northeast" : SAREA"plain2",
        ]) );
        set("objects" , ([
           "guard#1" : SMOB"guard1",
           "guard#2" : SMOB"guard1",
        ]) );
	reset();
}
