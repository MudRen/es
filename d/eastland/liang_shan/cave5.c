#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short("��Ѩ");
	set_long( @C_LONG_DESCRIPTION
�������ɽ���ϵĶ�Ѩ����Ѩ�����ܲ����˻�ѣ��յ�����һƬ��������\��ɽ��
�ڶ�Ѩ��������ȥ��ֻ��������ע�⵽��Ľ����Ͷ�Ի��ɵ�Ŀ�⡣
C_LONG_DESCRIPTION
	);

	set( "light",1);
	set( "exits", ([ 
		"out" : TROOM"yard1", 
		"eastdown" : TROOM"cave4" ]) );
	reset();
}
int clean_up() { return 0; }