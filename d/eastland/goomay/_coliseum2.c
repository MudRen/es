// File: /d/eastland/goomay/coliseum2.c
// Generated by Roommaker Thu Nov 23 18:50:31 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("�䶷���᳡");
	ob->set_long( @LONG_DESCRIPTION
������ÿһ��ϰ������������ĳ����أ����µ�һ�䶷���᳡������Ƭ
�����Ļ᳡�ϣ�������\���������Ӻͼ�����ӣ��˿�������\�����ڳ��ϣ�����
��\�������ȭ������������ʱ������ǰ����һ��դ�ţ�����Դ����뿪(leave)
�䶷��᳡��
LONG_DESCRIPTION
	);

	ob->set_outside( "eastland" );
	ob->set( "PK_ZONE", 1 );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/goomay/coliseum3", 
		"leave" : "/d/eastland/goomay/row25", 
		"west" : "/d/eastland/goomay/coliseum1", 
		"south" : "/d/eastland/goomay/coliseum5", 
		"north" : "/d/eastland/goomay/coliseum5" ]) );
	ob->reset();
}