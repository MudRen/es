#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_short("回廊一角");
	set_long(
@CLong
这里是走廊的转角, 一道楼梯 (stairs) 通往楼上的客房。由楼梯走
下来正好面对著一扇窗子 (window), 透过窗户可以看到外面的大街。
    往南可以回到旅馆的大厅。
CLong
);

	set( "c_item_desc", ([
		"stairs"	: @ITEM_STAIRS
你看到一道木头作的楼梯, 一边靠著墙壁, 另一边则有一道扶手, 中间
约有可容两人并行的宽度。由这道楼梯可以通往楼上的客房, 楼梯下面
的空间则被封起来, 侧面开了一道木门 (wooden door)。你想那应该是
一间小储藏室。 
ITEM_STAIRS
		, "window"	: @ITEM_WINDOW
这是一扇木窗, 可以分两边向外推开。窗台离地面大概一公尺左右, 从
窗户看出去, 你可以看到外面的大街与街上来往的行人。
你注意到窗子上的锁似乎被撬坏了。
ITEM_WINDOW
	]) );

	set("exits", ([
		"up"		: HERE"corridor2",
		"south"		: HERE"tavern",
		]));
	set("pre_exit_func", ([
		"up"		: "make_bedroom",
		]) );
}

int		make_bedroom()
{
	object	ob;
	object	bedroom;
	
	ob = present( "copper key", this_player() );
	if (ob && (base_name(ob) == OBJ"tavern_key"))
	{
		printf("%s", "你走上楼, 找到了你的房间, 用老板给你的钥匙打开房门。\n");
		bedroom = clone_object( HERE"bedroom" );
		this_player()->move_player(bedroom, "", "up");
		return 1;
	}
	
	ob = present( "silver card", this_player() );
	if (ob && (base_name(ob) == OBJ"silver_card"))
	{
		printf("%s", "你上楼, 走进自己的房间。\n");
		bedroom = clone_object( HERE"bedroom" );
		this_player()->move_player(bedroom, "", "up");
		return 1;
	}
	
	printf("%s", "你还没订房间, 上去了也没有用。\n");
	return 1;
}