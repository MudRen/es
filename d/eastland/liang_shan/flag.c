#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "大演武场" );
	set_long(
	"这里是山寨内著名的大演武场，平时豹\子头林冲都在此操练部下．训\n"
	"练格斗或阵法．场边放著各式的兵刃，发出森森的寒光．如果你想加入山\n"
	"寨，最快的方法就是在此显显身手．这里竖著几面旗帜，吸引你的目光\n"
	);
	set( "light",1 );
        set_outside( "eastland" );
        set( "c_item_desc",(["flag":
        "这些旗帜高耸入云，直插天际，如果轻功不好，是上不去的\n"
        ]));
        set( "exits", ([
                "east" : TROOM"plaza2",
                "south"  : TROOM"path2",    
                "north"  : TROOM"plaza5",
                "west" : TROOM"plaza1"
        ]) );
        set( "objects",([
                "bandit":TMONSTER"small_bandit",
                "zhu":TMONSTER"zhu"
        ]) );        
        reset();
}
void init()
{
add_action("do_climb","climb");
}
int do_climb(string arg)
{
if ( !arg || arg!="flag")
return notify_fail(
"爬什麽?\n");
write (
"还没完成, 请过两天来爬\n");
}
int clean_up() { return 0; }