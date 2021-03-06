#include "ruin.h"
inherit ROOM;

#define GARGOYLE_NUM_ONCE 4
#define GARGOYLE_NUM 2
#define MAX_GARGOYLES 16

void create()
{
	::create();
	set_outside("noden");
	set_short("遗迹");
	set_long(@CLong
两排古老的石雕像 (statues)、 散乱倒在地上的石块 (stones)、仅
馀半截立在地上的石柱群, 从前这里大概是某个充满著光辉、荣耀的神殿
吧! 但是时光逝去, 光华不再, 连在此被奉祀的神祈之名, 也因年代久远
渐渐地被人遗忘, 不得而知了。在杂乱的石柱群中, 一个人工开凿的洞穴
被半遮半掩地隐藏在北方的山壁上。南边则是通往南方山丘地带的小径。
CLong
);
	set("exits",([
              "south"	: RUIN"hidden_path4",
              "north"	: RUIN"s_hall",
             ]));
    set("exit_suppress", ({ "north", }) );

	add("item_desc", ([
		"statues": @C_ITEM_DESC_1
    这些石像都是以石像鬼 (gargoyle) 的造型来塑造的, 但是各有各的
姿态, 栩栩如生。或许\他们曾经真的「活过」, 不过经过了那麽久的时间
, 魔力大概早已消失无踪了。
C_ITEM_DESC_1
,		"stones"	: @C_ITEM_DESC_2
    一堆散乱的石头, 这些都是原来那个不知名的伟大建筑中的一部份。
有些石头上还可以隐约地看到优美的雕刻图案。
C_ITEM_DESC_2
,		"tunnel": @C_ITEM_DESC_3
    与其称它为一个洞穴, 还不如称它为通道比较恰当, 洞穴的墙壁都是
石砌的, 四面相当的宽广, 似乎通往相当深的地方。不过你隐隐约约感受
到洞口传来一股斥力。
C_ITEM_DESC_3
		]));
		
	set( "pre_exit_func", ([
		"north" : "loop_exit" ]) );
//	set( "search_desc", ([
//    	"here" : "@@search_here" ]) );
	set("seal", GARGOYLE_NUM);
	reset();
}

int loop_exit()
{
	int i;
	object me, storage;
	
	me = this_player();
	if( !me->query("invisible") && present( "gargoyle", this_object() ) ) {
		write( 
		"石像鬼挡住了你的去路, 使你无法进入洞穴。\n");
		tell_room( environment(me), 
	sprintf("%s想进入洞穴, 但是被石像鬼挡住了。\n", me->query("c_name"))
		, me);
		return 1;
    } 
	if( me->query("invisible") || query("seal") < 1 ) return 0;
	write( 
	"你正想向洞穴走去, 突然间一阵奇异的光由石块中发出, 挡住了你的去路。\n"
 	"紧接著四只石像鬼眼睛一亮, 活了起来。\n" 
	);
	tell_room(this_object(),
		sprintf("%s正想往洞中走去, 突然间一阵奇异的光芒由石块中发出。紧接著四\n"
			"只石像鬼眼睛一亮, 活了过来\n", me->query("c_name"))
		, me
	);
	tell_room(find_object(RUIN"mob_storage"),
		"突然间一阵奇异的光芒由石雕像的眼中发出。又有四只石像鬼活了过来。\n"
	);
	storage = find_object_or_load(RUIN"mob_storage");
	for( i=0; i<GARGOYLE_NUM_ONCE; i++ ) {
		if( (int)storage->query("mob_storage") < MAX_GARGOYLES )
			storage->add("mob_storage", 1);
		new(MOB"gargoyle")->move(storage);
		new(MOB"gargoyle")->move(this_object());
	}
	add("seal", -1);
	return 1;
}

void reset()
{
	::reset();
	set("seal", GARGOYLE_NUM);
}
