//#pragma save_binary

#include "farwind.h"

inherit ROOM;

int box_moved;

void create()
{
	::create();
	set_short( "铁匠铺" );
	set_long(@C_LONG
这是远风镇上唯一的一家铁匠铺，老铁匠平时最喜欢和年轻的冒险者谈
论他年轻时的游历。但是最近为了对抗敌人的侵略，王宫来的使者订了好几
千套盔甲，他不得不加紧赶工。在铁匠铺的一个角落里堆著一些箱子(boxes)
。
C_LONG
               	);
	set( "light", 1 );
	set( "exits", ([
		"west" : FARWIND"smain2"
	]) );

	set( "item_func", ([
		"boxes" : "exam_boxes"
	]) );
	box_moved = 0;

	set( "objects", ([
		"smith" : FARWIND"monster/smith"
	]) );
	reset();
}

void init()
{
	add_action( "do_move", "move" );
	add_action( "do_climb", "climb" );
}

void exam_boxes()
{
	object smith;

	if( !box_moved ) {
		write( 
			"这堆箱子零零散散地堆在一起，占去了整个铁匠铺一半的面积。\n"
		);
		if( (smith= present("smith", this_object())) && smith->query("npc") )
			write( 
				"老铁匠作个手势，告诉你不要乱动(move)那些箱子。\n"
			);
	} else {
		write( 
			"这堆箱子中间被人搬开了一些，露出一到往下的梯子(ladder)。\n"
		);
		if( (smith= present("smith", this_object())) && smith->query("npc") )
			write( "老铁匠告诉你: 地下室有不少老鼠，很凶喔。\n");
	}
}

int do_move(string arg)
{
	if( !arg || arg!= "boxes" ) return 0;
	if( box_moved ) {
		write( "你小心地把那些箱子搬回原位，遮住了那个向下的梯子。\n");
		box_moved = 0;
		delete( "item_desc/ladder" );
	} else {
		write("你小心地把那些箱子搬开，发现了一个向下的梯子(ladder)！\n"
		);
		box_moved = 1;
		add( "item_desc", ([ "ladder":
			"从这个梯子往下看一片漆黑，不知道爬(climb)下去会有什麽危险？\n"
		]) );
	}
	return 1;
}

int do_climb(string arg)
{
	if( !box_moved ) return 0;

	this_player()->move_player( FARWIND"cellar1", "SNEAK" );
	return 1;
}
