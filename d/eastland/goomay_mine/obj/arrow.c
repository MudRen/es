#include <../zeus.h>

inherit OBJECT;

void create()
{
	set_name("singing arrow", "�����" );
	add("id",({"arrow"}));
	set_short( "...","�����" );
	set_long("..",
	"����һֻ����������Ƶļ���β������һ������϶�죬�н�ʱ��\n"
	"���������ŵ������������ĵ����飮���������εز��ڵ���\n"
	);
	set("unit","ֻ");
	set("weight", 5000 );
}