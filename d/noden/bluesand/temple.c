// File: /d/noden/bluesand/temple.c
// Generated by Roommaker Thu Nov 11 12:45:35 1993
// translation done 2-24-94 -Elon ANOTHER hard one?!?! *sigh*

#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
   set_short("土地庙");
	set_long( @LONG_DESCRIPTION
这是一间土地公庙，土地公是东方大国的人们普遍信仰的地方性神明，他
会保佑虔诚的信徒们多福多寿，并且避免地方上受到妖魔鬼怪的侵扰。你可以
看到一尊泥塑的土地公雕像(statue)坐在檀木桌上，袅袅的香烟衬托初一种宁
静祥和的气氛。
LONG_DESCRIPTION
	);
    set("c_item_desc",(["statue":@C_LONG
这是一尊很和蔼的土地公雕像，一位白发苍苍的老公公，伫著长长的拐杖，
笑咪咪的好像正在看望的他的土地。或许土地公是东方大陆的普遍信仰，但
在诺顿却很少见，你走上前去仔细打量他，却发现他十分乾净，好像有人每
天摸(touch)他似的。
C_LONG
		]) );
		
	set( "objects", ([
		"samurai": "/d/noden/bluesand/monster/samurai" ]) );
	set( "exits", ([
		"north" : "/d/noden/bluesand/alley2.c"
	]) );
	reset();
}
void init()
{
	add_action("do_touch","touch");
}

int do_touch(string arg)
{
	if ( !arg || arg != "statue" )
		return notify_fail("你要摸什麽？\n");
	if ( !query("exits/west") ) {
	write(@LONG
你伸出手摸摸土地公像，发现他有点摇晃，好像可以转动，於是你顺手
一转，突然「拍」的一声，西边出现一道暗门。
LONG
	);
	tell_room(this_object(),this_player()->query("c_name")+
	"伸手摸摸土地公像，突然「拍」的一声，西边出现了一道暗门。\n",
	this_player() );
	set("exits/west","/d/thief/hall/thief_guild");
   this_player()->set_explore("noden#36");
	return 1;
	}
	write("你摸摸土地公像，顺手转了他一下，把暗门关起来。\n");
	delete("exits/west");
	return 1;
}

void reset()
{
	delete("exits/west");
	::reset();
}
