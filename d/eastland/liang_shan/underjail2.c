#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "��������϶" );
	set_long(
	"������ɽ����Ȼ���ɵ���϶�����Խ��ȵ�ɽ�ʹ����һ��͸�������ĸо���\n"
	"һ��������������ͷ�����£���Ȼ��һ������̾����Ȼ�Ĺ��񹤣���һ\n"
	"������ȴ�ְ�����������ʹ���ͨ�и������ѡ��ټ��ϵ���ʪ�����ģ����\n"
	"���С�ĵ�ǰ�����⻬����\n"
	);
        set( "exits", ([
                "southeast" : TROOM"underjail3"
        ]) );
        reset();
}
int clean_up() { return 0; }
