#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(7);
	set_name( "librarian", "ͼ���Ա" );
	set_short( "ͼ���Ա" );
	set_long(@CLONG
��λ��������˹��������С�����ŵ�����Ǵ�ͼ��ݵ�ͼ���Ա������
������ʲ���飬ֻҪ��(ask)����Ҫ��Ѱ�����⣬���ͻ�������顣
CLONG
	);
	set( "no_attack", 1 );
	set( "gender", "female" );
	set( "race", "elf" );
	set( "inquiry", ([
		"ALL_TOPIC" : "@@seek_book"
	]) );
}

void seek_book( object player )
{
	tell_object( player,
		"ͼ���Ա����˵��: �ܱ�Ǹ�����ͼ����������ޣ���ͣ����....��\n"
	);
}
