#include "../dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "south2", "��н���塻�㳡" );
	set_long(@C_LONG
����һ��Ƭ��ɰ�㳡, ��Ϊ��ؤ����ӳ��ڴ˴����书, ���Ե����Եù�
ͺͺ��һ���Ӳ�Ҳû�С���ʱ���εĺܴ�Ю��������Ļҳ�, ������ÿ���ϱ�
�ĸ�ɽ��������ɽ�硻, ������۾�����������ǡ�ؤ��ⶨ��һЩˮ������
�Ĺ���, ���Ǵ���ȱ����һ��Ƭ�յؿ��Թ���������ϰ, ����ÿ�������ֵ��Ƥ
�Ĺ����ͻ����˷���, ��Ǻ����ǻ��ǵü���������ȥ�����������Ϻͱ��߶���
�㳡�ļ������ꡣ
C_LONG
	);
	set_outside( "noden" );
	set( "exits", ([
                      "east":DBEGGAR"s2e1.c",
                      "west":DBEGGAR"s2w1.c",
                      "south":DBEGGAR"south3.c",
	              "north":DBEGGAR"south1.c"
	]) );
     reset();
}

