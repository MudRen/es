#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short("����");
	set_long( @C_LONG_DESCRIPTION
������һƬƽ̹��ɳ�أ���ϸ�Ļ�ɳʹ��������ᣬ����һ���������ӡ��ż��
��紵�𣬺��淺���������������������г���֮�룬ɳ���ԵĲݴԳ����˲�֪����
Ұ�������߲�Զ�ƺ��м����˼ҡ�
C_LONG_DESCRIPTION
	);

	set_outside("eastland");
	set( "exits", ([ 
		"west" : TROOM"beach7",
		"north" : TROOM"village1" ]) );
	reset();
}
