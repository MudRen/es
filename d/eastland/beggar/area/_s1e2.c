// File: /d/eastland/beggar/area/s1e2.c
// Generated by Roommaker Thu Mar 21 18:06:58 1996

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("��н���塻�㳡");
	ob->set_long( @LONG_DESCRIPTION
����һ��Ƭ��ɰ�㳡, ��Ϊ��ؤ����ӳ��ڴ˴����书,���Ե����Եù�ͺ
ͺ��һ���Ӳ�Ҳû�С���ʱ���εĺܴ�Ю��������Ļҳ�,������ÿ���ϱߵĸ�
ɽ��������ɽ�硻,������۾�����������ǡ�ؤ��ⶨ��һЩˮ�����ֵĹ���
,���Ǵ���ȱ����һ��Ƭ�յؿ��Թ���������ϰ, ����ÿ�������ֵ��Ƥ�Ĺ�����
�����˷���, ��Ǻ����ǻ��ǵü���������ȥ��������һƬ����,�����ϱ��ǹ㳡
�ļ�������, �������ǵ�·��
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "exits", ([ 
		"north" : "/d/eastland/beggar/area/east2.c", 
		"south" : "/d/eastland/beggar/area/s4e2.c", 
		"west" : "/d/eastland/beggar/area/s1e1.c" ]) );
	ob->reset();
}