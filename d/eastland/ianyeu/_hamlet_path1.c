// File: /d/eastland/ianyeu/hamlet_path1.c
// Generated by Roommaker Wed May 15 19:37:15 1996

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("С��");
	ob->set_long( @LONG_DESCRIPTION
��������������ڵ�С���ϡ�������ǰ��ʱ, ��о���
����ƺ�������ϡ��; ������������, ��С·�϶��Ӳݴ���,
�㲻���������Ƿ�Ϊһ�������Ĵ�ׯ! ������ע�⵽�ڶ���
����������һ��С�ݡ�
LONG_DESCRIPTION
	);

	ob->set_outside( "eastland" );
	ob->set( "exits", ([ 
		"southwest" : "/d/eastland/13,14.east", 
		"east" : "/d/eastland/ianyeu/wang_home", 
		"north" : "/d/eastland/ianyeu/hamlet_path2", 
		"west" : "/d/eastland/ianyeu/hunter_house" ]) );
	ob->reset();
}