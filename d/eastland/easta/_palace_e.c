// File: /d/eastland/easta/palace_e.c
// Generated by Roommaker Sat Nov 25 17:10:42 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("��᰹�������");
	ob->set_long( @LONG_DESCRIPTION
��������������᰹����ߵ������ţ��ߴ�Ĺ�������װ��������ȭͷ���ͭ
�������յĹ��ź͸ߴ�Ĺ�ǽ͸��һ�ɹ�͢��������գ���᰹���������������
���ﶼ�����ܵ��ػ����������ǿ����Ķ���֣����������ԶԶ��������ᰳǵ�
���ţ�������ǽ����ʯ��·���������Ϸ����졣
LONG_DESCRIPTION
	);

	ob->set_outside( "easta" );
	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/easta/east_malley", 
		"south" : "/d/eastland/easta/palace_se", 
		"north" : "/d/eastland/easta/palace_ne" ]) );
	ob->set( "objects", ([ 
		"guard#3" : "/d/eastland/easta/monster/palace_guard", 
		"guard#2" : "/d/eastland/easta/monster/palace_guard", 
		"guard#1" : "/d/eastland/easta/monster/palace_guard", 
		"guard#4" : "/d/eastland/easta/monster/palace_guard" ]) );
	ob->reset();
}