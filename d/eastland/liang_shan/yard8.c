#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "小庭院" );
	set_long(
	"这是忠义堂後的小小庭院，面积似乎不大，但花木扶疏，举目四望，\n"
	"竟种满了无数梅花，婉约娟秀，别有一番滋味。清风徐来，梅花特有的\n"
	"清香弥漫在风中....\n"
	);
        set_outside("eastland");
        set( "pre_exit_func", ([
                "south" : "check_leave",
                "east"  : "check_leave",
                "north" : "check_fall"
        ])) ;        
        set( "exits", ([
                "east" : TROOM"yard7",
                "south" : TROOM"yard8",
                "north" : TROOM"yard8",
                "west": TROOM"yard9"
        ]) );
        reset();
}
int check_leave()
{
write(
"你拨开树丛，钻了进去，但这片梅林似乎无穷无尽。\n");
return 0;
}
int check_fall()
{
write(
"你拨开树丛，钻了进去，忽然脚下一空，跌进一个大陷坑。\n");
this_player()->move_player(TROOM"fall1","SNEAK");
return 1;
}
int check_shut()
{
write(
"你拨开树丛，钻了进去，不知触到什麽机关，如雨射下一堆箭矢。\n");
this_player()->set("hit_points",(int)this_player()->query("hit_points")-15);
return 0;
}
int clean_up() { return 0; } 