#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("������ͤ");
	set_long( @LONG
�����ں���һ����ɫ�����������ͤ�ͤ����浴�����̲����ۡ���ͤ��
����ͥ�������̸���鹣���Χ���ܣ��仨���룬��Ϊ�ʡ����Σ�����������������
Ƣ�������Χ��һȦ���߸ߵ�ɺ����������������ʯ������Է���һ�ģ��淢����
ʮ�㣬������ͤһ����ͤ��һ��ˮ�����ţ����ξ�ϸ������������ҫ�����ԡ�

LONG
	);
        set("light",1);
        set("exits" , ([
             "bridge" : SPALACE"bridge2",
        ]) );
        set("objects", ([
           "servant#1" : SPMOB"f_se1",
           "servant#2" : SPMOB"f_se1",
           "servant#3" : SPMOB"f_se1",
               "queen" : SPMOB"queen1"
        ]) ); 
	reset();
}
