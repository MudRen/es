#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "СͥԺ" );
	set_long(
	"�������������ССͥԺ������ƺ����󣬵���ľ���裬��Ŀ������\n"
	"������������÷������Լ���㣬����һ����ζ�����������÷�����е�\n"
	"���������ڷ��У����������Լ䣬��Լ����һ��С����....\n"
	);
        set_outside("eastland");
        set( "pre_exit_func", ([
                "east" : "check_east"
        ])) ;        
        set( "exits", ([
                "east" : TROOM"room1",
                "north" : TROOM"yard4"
        ]) );
        reset();
}
int check_east()
{
write(
"�㲦�����ԣ�����һ��С�鷿��\n");
return 0;
}
int clean_up() { return 0; }