#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "������" );
	set_long(
		"����һ���¸ǺõĹ����ң���Ŀǰ�յ�����û���κζ�����Ҳ�����һ��\n"
	"Ҫ���ľ����������һЩ������\n"
	);
	set( "exits", ([
		"guild" : "/d/wiz/wiz_hall"
	]) );
}
