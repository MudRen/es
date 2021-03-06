#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
   set_short("蓝沙港码头");
	set_long( @LONG_DESCRIPTION
这里是蓝沙港的码头，规模虽然不是很大，但是诺顿王国和东方大国
的贸易几乎都要经过这里，在码头上你可以看到各式各样的船只(ship)与
箱子(boxes)，里面装的大部分都是来自东方的货品，只有少部份是诺顿王
国的货物。
LONG_DESCRIPTION
	);

	set_outside( "noden" );
	set( "light", 1 );
	set( "c_item_desc", ([ 
		"ship" : @LONG_TEXT
这些船只有的双桅，有的三桅，看起来都是建造成适合远航的样子，你注意
到一艘用白漆在船身漆著「比亚蓝号」的船停泊在码头的东边不远处，如果
你会游泳(swim)，也许可以游过去看看。\n
LONG_TEXT
, 
		"boxes" : "这些箱子整整齐齐地堆在码头上，等待码头工人过来搬运。\n" ]) );
    set( "exits", ([ 
		"west" : "/d/noden/bluesand/port_r2" ]) );
	set( "objects", ([
		"jeff" : "/d/noden/bluesand/monster/jeff" ]) );
	reset();
}

void init()
{
	add_action("do_swim", "swim" );
	if( !find_object("/d/std/ocean/ship_iriah") )
		"/d/std/ocean/ship_iriah"->frog();
	if( !find_object("/d/std/ocean/ship_death") )
		"/d/std/ocean/ship_death"->frog();
}

int do_swim()
{
    int swim_skill;

	swim_skill = (int)this_player()->query_skill("swimming");
	if( random(swim_skill) < 20 ) {
            write(
                    "你喝了几口又冷又咸的海水，狼狈地爬回岸上。\n" );
            tell_room( this_object(),
this_player()->query("c_cap_name")+"跳进海里，用可笑的姿势游了几公尺，然後狼狈地爬回岸上。\n",
			this_player() );
		return 1;
	}
   write(
"你跳进冰冷的海水，奋力向那艘船游去，终於抓到船身旁的缆绳，爬上船头。\n" );
    tell_room( this_object(),
          this_player()->query("c_cap_name")+"跳进海里，游向东边的一艘船上。\n",
		this_player() );
	this_player()->move_player("/d/noden/bluesand/ship", "SNEAK");
	return 1;
}

