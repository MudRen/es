// File: /d/noden/hawk/room1-19.c
// Generated by Roommaker Mon Sep 30 10:33:14 1996

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("��Ӫ��վ");
	ob->set_long( @LONG_DESCRIPTION
������ľ�Ӫ������Կ����ܶ������ʿ����������Ŭ���Ķ����Լ�����
�գ�ϣ���������������Լ��ĵ�λ��Ҳ�����������������˺���ζ��ߺ�ȵ�
��������������һ���ʵ�С��̨������վ�˸��ڱ�������۲���˵Ķ���
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"down" : "/d/noden/hawk/room1-12" ]) );
	ob->set( "objects", ([ 
		"soldier" : "/d/noden/hawk/monster/soldier", 
		"scout" : "/d/noden/hawk/monster/scout", 
		"soldier1" : "/d/noden/hawk/monster/soldier" ]) );
	ob->reset();
}