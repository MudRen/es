// File: /d/eastland/liang_shan/plaza3.c
// Generated by Roommaker Tue Nov 21 16:00:45 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("�����䳡");
	ob->set_long( @LONG_DESCRIPTION
������ɽկ�������Ĵ����䳡��ƽʱ����ͷ�ֳ嶼�ڴ˲������£�ѵ
���񶷻��󷨣����߷�����ʽ�ı��У�����ɭɭ�ĺ��⣮����������ɽ
կ�����ķ��������ڴ��������֣�
LONG_DESCRIPTION
	);

	ob->set_outside( "eastland" );
	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/liang_shan/path4", 
		"south" : "/d/eastland/liang_shan/plaza2", 
		"north" : "/d/eastland/liang_shan/bed3", 
		"west" : "/d/eastland/liang_shan/plaza5" ]) );
	ob->set( "objects", ([ 
		"vendor" : "/d/eastland/liang_shan/monster/black_vendor" ]) );
	ob->reset();
}