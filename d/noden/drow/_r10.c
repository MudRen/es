// File: /d/noden/drow/r10.c
// Generated by Roommaker Mon Nov 27 14:20:35 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("����լԺ");
	ob->set_long( @LONG_DESCRIPTION
������һ��������լԺ���Ͱ���Χǽ�ϣ���Ȼ�����֩���ͼ�ƣ�
СС��ͥԺ��ֲһЩ����ֵֹ��߲ˣ�һ��ʯ������ͥԺ�����룬Ҳ��
�Ǻڰ��������ԵĽڼ�ɣ��⿴����ʵ��ͥԺ���������ǹ���ƽ�վ�ס
�ĵط����㲻�����룬�ڰ�����Ľڼ���ܸ����ǵ�������йذɡ�
LONG_DESCRIPTION
	);

	ob->set( "light", 0 );
	ob->set( "exits", ([ 
		"west" : "/d/noden/drow/r09" ]) );
	ob->set( "objects", ([ 
		"Pan" : "/d/noden/drow/mob/pan" ]) );
	ob->reset();
}