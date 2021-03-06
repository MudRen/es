// File: /d/eastland/ianyeu/guey_home.c
// Generated by Roommaker Wed May 15 19:35:29 1996

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("民宅");
	ob->set_long( @LONG_DESCRIPTION
这是一间砖造的平房。虽然屋内仍摆\置著许\多家俱,
但是却都堆积著厚厚的一层灰尘, 甚至在墙角等阴暗之处还
有蛛网! 可见得此屋不是无人居住, 即是主人无心打扫....
就在你想离去之时, 你发现在墙角处竟有一张桌子特别乾净!
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "c_item_desc", ([ 
		"tablet" : "一个紫檀木刻成的灵位牌, 上面写著『爱女筱梅(sheaumei)之灵』。\n", 
		"table" : @LONG_TEXT
一张擦拭得洁净十分的檀木桌, 桌上除了一些鲜花素果外, 你还看到有一个牌位(tablet)。
LONG_TEXT
 ]) );
	ob->set( "exits", ([ 
		"west" : "/d/eastland/ianyeu/hamlet_path2" ]) );
	ob->set( "objects", ([ 
		"mother" : "/d/eastland/ianyeu/monster/guey_mother" ]) );
	ob->reset();
}
