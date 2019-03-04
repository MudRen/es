#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short(  "СͥԺ" );
	set_long(
	"�������������ССͥԺ������ƺ����󣬵���ľ���裬��Ŀ������\n"
	"������������÷������Լ���㣬����һ����ζ�����������÷�����е�\n"
	"���������ڷ���....\n"
	);
        set_outside("eastland");
        set( "pre_exit_func", ([
                "west" : "check_fall",
                "south" : "check_shut",
                "east"  : "check_leave",
                "north" : "check_shut"
        ])) ;        
        set( "exits", ([
                "east" : TROOM"yard7",
                "south" : TROOM"yard6",
                "west" : TROOM"yard4",
                "north": TROOM"yard4"
        ]) );
        reset();
}
int check_leave()
{
write(
"�㲦�����ԣ����˽�ȥ������Ƭ÷���ƺ������޾���\n");
return 0;
}
int check_fall()
{
write(
"�㲦�����ԣ����˽�ȥ����Ȼ����һ�գ�����һ�����ݿӡ�\n");
this_player()->move_player(TROOM"fall1","SNEAK");
return 1;
}
int check_shut()
{
write(
"�㲦�����ԣ����˽�ȥ����֪����ʲ����أ���������һ�Ѽ�ʸ��\n");
this_player()->set("hit_points",(int)this_player()->query("hit_points")-15);
return 0;
}
int clean_up() { return 0; } 