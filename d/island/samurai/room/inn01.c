#include <mercury.h>

inherit ROOM;

void create()
{
	::create();
	set_short("千川楼前庭");
	set_long(@AAA
你来到千川楼的前庭，在道路的两旁种植著一排排的灌木，还有一个接一
个排在一旁的精美雕像，而道路的左边还有一个大喷泉，奇怪的是这个喷泉里
居然都没有长青苔，可见打扫人的勤劳．	
AAA
	);

	set_outside( "eastland" );
	set( "search_desc",([
	     "here":@AAA
你在这里仔细搜索之後，发现这个喷泉(fountain)怪怪的！！　
AAA
]));
	set( "c_item_desc", ([ 
		"fountain" : @LONG_TEXT
这道喷泉你仔细观察之後，发现在泉水喷出处似乎有一个暗色的
铁板盖板，你可以试著潜水(dive)下去看看．
LONG_TEXT
 ]) );
	set( "exits", ([ 
		"north" : MR"inn02", 
		"south" : MR"cac08" ]));
	set( "water_source",1 );
	reset();
}

void init()
{
	add_action( "do_dive", "dive" );
}

int do_dive(string arg)
{
	if( !arg || arg == "" || arg!="fountain" ){
		tell_object( this_player(), "你要潜去哪里呀？\n" );
	        return 1;
	} 
        if( random( (int)this_player()->query_skill("swimming") ) < 5 ) {
		write( "你想潜入喷泉，却被喷泉的水流给冲了回来\n" );
		return 1;
	}
	write( "你奋力潜向喷泉底部，果然不出所料，喷泉下还有一个通道\n"
		 );
	this_player()->move_player( MR"tube01", "SNEAK" );
        this_player()->set_explore("island#11");
	return 1;
}

