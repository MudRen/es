#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("陵墓深处");
	set_long( 
@C_LONG_DESCRIPTION
你来到了陵墓的最深处。一具巨大的玉棺放置於此，上面有著东方王国的国徽，它的外
型古拙，而且找不任何一丝的接缝，就像是从一大块巨大的玉石中雕刻出来似的，你想这应
该就是皇帝的棺木吧。四周的墙壁都是用黄金打造而成，上面一共镶了九条白金铸成的飞龙
，气派非凡。你可以看到在石棺前的供桌上有著龙袍、皇冠、以及一颗闪闪发光的红宝石，
这就是在南边可以看到红光的原因。
C_LONG_DESCRIPTION
	);

	set( "light",1);
	set( "exits", ([ 
		"south" : TOMB"/inner5" ]) );
	set( "objects", ([
		"robe" : ITEM"/robe",
		"crown" : ITEM"/crown",
		"ruby" : ITEM"/ruby" ]) );
	set( "pre_exit_func", ([
		 "south" : "check_eq" ]) );
	reset();	
}

void init()
{
  if( this_player()) this_player()->set_explore("eastland#36");
}
int check_eq()
{
	if ( !present( "emperor robe", this_object() ) || !present( "emperor crown", this_object() ) )
	{	tell_room( this_object(),
		"\n"+"突然一块巨大无比的石头 ---- 「隔世石」，掉下来挡住南边的出口。\n" );
		delete( "exits/south" );
		return 1; }
	else return 0;
}
