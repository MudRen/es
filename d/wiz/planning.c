#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "企划室" );
	set_long(
			"这里是巫师们作企划的地方，如果你正在作某个企划，希望其它巫\n"
		"师帮忙或提供意见的，可以在这里留言( 或者是广告 )。西边是巫师的\n"
		"点子中心，往东可以回到巫师办公室。\n"
	);
	set( "light", 1 );
	set( "exits", ([
		"east"	:	"/d/wiz/wiz_office",
		"west"	:	"/d/wiz/ideas"
	]) );

	// Cause the plan_board to load
	call_other( "/d/wiz/plan_board", "???" );
}
