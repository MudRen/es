// translation done -Elon 03-10-94
#include "../moyada.h"
#include "anthill.c"

inherit ROOM;
int find;

void create()
{
	::create();
	set_short("垃圾坑");
	set_long( @C_LONG_DESCRIPTION
这里似乎已是蚁穴的底部，到处堆著巨蚁们的废弃物。排泄物(excreta)、
食物残渣(dump)，那臭味令你难受极了，你只想尽快的离开这里。
C_LONG_DESCRIPTION
	);
	set( "objects", ([
	   "yellow slime"   : MOYADA"monster/yellow_slime",
	   "green slime"    : MOYADA"monster/green_slime",
	   "red slime"      : MOYADA"monster/red_slime",
	]) );
	set( "search_desc", ([
	  "dump" : "@@search_dump",
	]) );
	set( "item_desc", ([
	  "excreta" : "尽是蚂蚁的排泄物，臭死了。\n",
	  "dump" : "蚂蚁们吃剩的食物，不晓得它们为何如此浪费。\n"+
	           "仔细一看里面好像有什麽东西在骚动。\n",
	]) );
	reset();
}

void reset()
{
    ::reset();
    if( !present("metal slime", this_object()) ) find = 0;
}

int search_dump()
{
	object ob;

	if( find ) return 0;
   if( this_player() ) this_player()->set_explore("noden#10");
	ob = new( MOYADA"monster/metal_slime" );
	ob->move( this_object() );
	tell_room( environment(this_object()),
		"突然一只金属史莱姆从垃圾堆中跳了出来，对著你微笑。\n" );
	find = 1;
	call_out( "disappear", 200, ob );
	return 1;
}

void disappear(object ob)
{
	object *item;
	int i;

	if( !ob ) return;
	tell_room( environment(ob), 
		"你眼前的金属史莱姆突然消失了。\n" , ob
	);
	item = all_inventory(ob);
	for( i=0; i<sizeof(item); i++ ) item[i]->remove();
	ob->remove();
}

void init()
{
	add_action("to_climb", "climb");
}

int to_climb( string str )
{
	if( !str || str=="" )
		return notify_fail("你要爬哪个方向?\n");
	if( str != "up" )
		return notify_fail("那个方向不通啦!\n");
	to_climb_up( this_player(), MOYADA"anthill/cellar3", 40 );
	return 1;
}
