// File: /d/noden/asterism/city54.c
// Generated by Roommaker Thu Nov 23 19:12:25 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("���д�·");
	ob->set_long( @LONG_DESCRIPTION
�����ǰ�˹���ɶ�(asterism)�ǵĴ��·, ��춰��������ɵ������ݼ����˵�
��������,����ĵ�·ʮ�ֿ�����ֱ, ���ҵ�·������ֲ����ľ�������໥����֮��, 
���˺��������һ�������Ĺ�԰�����������̵ĳ�ǽ, ����������紵��ɹ, ��Ȼ
������ҡ��
LONG_DESCRIPTION
	);

	ob->set_outside( "asterism" );
	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"north" : "/d/noden/asterism/city53", 
		"west" : "/d/noden/asterism/city_entrance", 
		"south" : "/d/noden/asterism/city55" ]) );
	ob->reset();
}