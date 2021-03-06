#include <almuhara.h>

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
	set_short("屋内");
	set_long( 
@C_LONG_DESCRIPTION
这是一个整理得相当乾净的大厅，四周有些用竹子作成的家具，整个屋子令人觉得相当
朴实典雅。室内有一股淡淡的清香，令你精神为之一振。正中央有一个小小的供桌，桌上祭
拜著一个道士，不知道是何方神圣。左边墙上挂了一把剑，右边则是一幅很大的壁画，上面
画著一些奇怪的文字及符号，还有一条条弯弯曲曲的线条。
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"north" : TOMB"/house4",
		"south" : TOMB"/house3", 
		"out"   : TOMB"/house1" ]) );
	create_door( "out","enter",
		(["keyword" : ({"door"}),
		  "name"    : "red door",
		  "c_name"  : "红门",
		  "c_desc"  : "一扇红色的门。",
		  "status"  : "closed",
		  ]) );
	set( "objects", ([
		"boy#1" : MOB"/good_boy",
		"boy#2" : MOB"/evil_boy" ]) );
	set( "pre_exit_func", ([
		"south" : "check_boy" ]) );
	reset();	
}

int check_boy()
{
	object player;
	
	player = this_player();
	if( present("broken jade",player) ) {
		write( "小童看了看你身上的碎玉佩，说道 : 「 你是来找我家女主人的喔，请进。」\n" );
		return 0; }
	if( present("old scroll",player) ) {
		write( "小童看了看你身上的画轴，说道 : 「 你是来找我家女主人的喔，请进。」\n" );
		return 0; }
	if ( !wizardp(player) && present( "boy", this_object() ) ) {
		write( "小童说道 : 「 喂 !! 你这人懂不懂礼貌啊 ?? 随随便便就往人家的内室闯 !! 」\n" );
	return 1; 
	} else return 0;	
}
