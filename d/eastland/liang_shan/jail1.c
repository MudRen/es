#include <takeda.h>

inherit DOORS;
inherit ROOM;

void create()
{
	::create();
	set_short("监牢");
	set_long( @C_LONG_DESCRIPTION
你现在进入了一间漆黑的地牢，唯一你可发现的出口就是锁起来的大铁门
，除此之外都是光滑的岩壁，你想这可能是挖空山壁所成的地牢，四壁浑然天
成，全无接缝。墙上很突兀的长了一株植物(herb)，墙角放了张小石床，光是
看著就觉得好冷好冷，更别说是睡了。
C_LONG_DESCRIPTION
	);

	set( "c_item_desc", ([ 
		"herb" : @LONG_TEXT
你觉得奇怪，为何在这种地方还有植物生长呢? 在赞叹造物主之馀不免多看了
它几眼，肥厚的叶片，墨绿色的斑纹，隐约散发出一股刺鼻的药味。
LONG_TEXT
, 
		"bed" : @LONG_TEXT
这张小床是用石头制成的，奇怪的是，它跟墙之间没有任何接缝存在，大概也
是山壁直接雕成的，而且这张石床冰寒彻骨，你怀疑真有人能睡在上面。
LONG_TEXT
 ]) );
	set( "exits", ([ 
		"east" : TROOM"jail2" ]) );
	create_door( "east", "west", ([
		"keyword" : ({"door", "iron door"}),
		"name" : "iron door",
		"c_name" : "铁门",
		"desc" : "A strudy iron door",
		"c_desc" : "一扇厚实的大铁门",
		"status" : "locked",
		"lock" : "LiangShankey-1"
	]) );
	reset();
}
int clean_up() { return 0; }