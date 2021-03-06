#include "../ekravia.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "old alchemist", "炼金术师" );
	add( "id", ({ "alchemist" }) );
	set_short( "老炼金术师" );
	set_long(@LONG
你看到一个穿著白色长袍的老者, 左手上正好拿著一个烧瓶。他看来正忙
著某种实验。大约是发现你的到来吧? 他停下手边的工作, 回过身来对著
你微笑。
LONG
	);
	set( "gender", "male" );
	set( "alignment", 500 );
	set( "wealth/silver", 1000 );
	set( "no_attack", 1 );
	set( "chat_chance", 15 );
	set( "chat_output", ({
		"老炼金术师亲切地问道:「需要什麽吗? 年轻人」\n",
		"老炼金术师回头埋首於他的实验。\n",
		"老炼金术师说道:「这里有不少上好的药剂, 自己参考一下清单吧!」\n",
	}) );
}
