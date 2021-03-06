#include "../takeda.h"

inherit ROOM;

void create()
{
	::create();
        set_short("奇怪的洞穴");
	set_long( @LONG_DESCRIPTION
你一踏进这个地方，全身莫名的有觉得一种舒畅的感觉，与外面的邪恶气息
完全不同，在你的面前有一块巨大的石碑 (stele)，看来好像相当古老了，虽然
岩壁上或多或少的有些青苔，但石碑上面却是光洁异常?
LONG_DESCRIPTION
	);

	set( "c_item_desc", ([ 
		"stele" : @LONG_TEXT
你走到石碑前，仔细的观察它的表面，上面刻著许多奇怪的文字，看来
不是现存的任何一种。大约离地四尺的地方，有一个[□]型的凹陷奇怪记号
(mark)。
LONG_TEXT
, 
		"mark" : @LONG_TEXT
你仔细的检查这个记号，看起来记号里面的材质跟石碑表面有点不一样?
但是光看是不能证明你的想法...		
LONG_TEXT
 ]) );
	set( "drag_appear",0 );
	set( "exits", ([ 
		"south" : TROOM"lair/lair2" ]) );
}


void init()
{
	add_action( "do_touch", "touch" );
}

int do_touch(string arg)
{
	object dragon;
	if( !arg || arg!= "mark" ) return 0;
        if ( present("dragon") ) return 0;
        if ( query("drag_appear") ) {
        tell_object(this_player(),
        "你摸了摸这个记号，一个悲伤的声音在你的内心出现: 【孩子，一切都太迟了....】\n"); 
        return 1;
        }
        tell_object(this_player(),
        "你摸了摸这个记号，一个庄严的声音在你的内心出现: 【孩子，我等你很久了....】\n"
        "你是来帮助我的吗??\n");
        tell_room( this_object(), 
        "突然一阵剧烈的波动，一个巨大的生物突然出现在你面前....\n"
		 );
	set( "drag_appear",1 );
	dragon =new(TMONSTER"drag");
	dragon->move(TROOM"lair/lair3");
	return 1;
}
int clean_up() { return 0; }