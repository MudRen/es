// File: /d/noden/nodania/upstair_1.c
// Generated by Roommaker Mon Dec  4 20:14:45 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("����");
	ob->set_long( @LONG_DESCRIPTION
������ŵ������������¥��һ�����ȣ�ƽ��ֻ�й��������ļ��˲Ż�������
���֣�����Կ������ྫ�µıڻ��븡��װ�������ߵ�ǽ�ڣ��ذ����ð�ɫ�Ĵ�
��ʯ�̳ɵģ�������һ���������໨�ܵĿ��л�԰�������ǳ��ȵ���һ�ˡ�
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"down" : "/d/noden/nodania/e_throne", 
		"south" : "/d/noden/nodania/hgarden", 
		"west" : "/d/noden/nodania/upstair_2" ]) );
	ob->reset();
}