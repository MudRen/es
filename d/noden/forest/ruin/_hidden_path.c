// File: /d/noden/forest/ruin/hidden_path.c
// Generated by Roommaker Mon Dec  4 21:20:34 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("�޾�");
	ob->set_long( @LONG_DESCRIPTION
С��������ǰ�����졣���ž������ȵ׵�·��! �����Ƿǳ�����
�����ӡ������˵���˼�����, �������ƺ�����������¡�С����������
�����������ĺۼ�, ��Ȼ������Щ����������̫�����˵�...
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "exits", ([ 
		"north" : "/d/noden/forest/ruin/hidden_path2", 
		"up" : "/d/noden/forest/ruin/plate" ]) );
	ob->set( "objects", ([ 
		"boar" : "/d/noden/monster/boar", 
		"falcon" : "/d/noden/monster/falcon" ]) );
	ob->reset();
}