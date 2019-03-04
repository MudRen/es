#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "小庭院" );
	set_long(
	"这是忠义堂後的小小庭院，面积似乎不大，但花木扶疏，举目四望，\n"
	"竟种满了无数梅花，婉约娟秀，别有一番滋味。清风徐来，梅花特有的\n"
	"清香弥漫在风中，东方的树丛间，隐约看到一间小房子....\n"
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
"你拨开树丛，进入一间小书房。\n");
return 0;
}
int clean_up() { return 0; }