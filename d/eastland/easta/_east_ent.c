// File: /d/eastland/easta/east_ent.c
// Generated by Roommaker Sat Nov 25 17:02:01 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("�����·��");
	ob->set_long( @LONG_DESCRIPTION
������������ᰳǶ����ڵĴ�֣���ᰳ�����᰹�Ϊ���ģ���������������
������֣�����������ԡ��ԡ�����������ֱ���ͬ����Ϊ����������Ĳ�\����
С��̯�����á���ζ��ı�ƣ������Ƕ���ֵ���Ҫ�ֵ���ͨ����᰹�������
�ţ���������������Ķ��š�
LONG_DESCRIPTION
	);

	ob->set_outside( "easta" );
	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/easta/eastgate", 
		"north" : "/d/eastland/easta/east_nlane", 
		"south" : "/d/eastland/easta/east_slane", 
		"west" : "/d/eastland/easta/east_malley" ]) );
	ob->set( "objects", ([ 
		"vendor" : "/obj/vendor" ]) );
	ob->reset();
}