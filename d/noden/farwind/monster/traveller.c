#include <mudlib.h>

inherit MONSTER;

string *rumors = ({
	"听说默尔斯帝国军最近又要来了，不知道这次他们会打哪一个城镇？",
	"如果你想到东方，可以到蓝沙港去等伊莉雅皇后号渡船。",
	"蓝沙港南边有一栋闹鬼的屋子，听说那里一夜之间死了七、八个人....",
	"你去过精灵村吗？我到现在还搞不清楚精灵村的正确位置。",
	"满月的时候塔姆姆族会出来猎人头，不想死的人最好别靠近河流的上游....",
});

void create()
{
	object ob1, ob2, ob3;

	::create();
	set_level( 7 );
	set_name( "traveller", "过路旅客" );
	set_short( "过路旅客" );
	set_long(@C_LONG
这个人看起来虽然疲惫不堪，但是你从他结实的肩膀和手臂可以看得出
他是一个很有经验的旅行家，如果你有时间，可以向他打听一些在这附
流传的一些流言(rumors)。
C_LONG
	);
	set_perm_stat( "str", 10 );
	set_perm_stat( "kar", 10 );
	set_skill( "longblade", 70 );
	set_skill( "parry", 40 );

	set( "gender", "male" );
	set( "race", "human" );
	set( "wealth", ([ "gold" : 10 ]) );
	set( "inquiry", ([
		"rumors" : "@@ask_rumors" ]) );

	ob1 = new( "/d/noden/farwind/items/rapier" );
	ob1->move( this_object() );
	wield_weapon( ob1 );

	ob2 = new( "/d/noden/farwind/items/gloves" );
	ob2->move( this_object() );
	equip_armor( ob2 );

	ob3 = new( "/d/noden/farwind/items/buskin" );
	ob3->move( this_object() );
	equip_armor( ob3 );
}

string ask_rumors()
{
	int i;

	i = random(sizeof(rumors)/2) * 2;
	if( environment() )
		tell_room( environment(),
			"过路旅客说道: " + rumors[i+1] + "\n",
			this_object() );
}
