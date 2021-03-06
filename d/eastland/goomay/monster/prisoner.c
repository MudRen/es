#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(7);
	set_name( "prisoner", "逃犯" );
	add( "id", ({ "man" }) );
	set_short( "逃犯" );
	set_long(
		"他是一个衣不蔽体的可怜人，脸上带著浓重的惊恐神情，好像正在躲避什麽。\n"+
		"你仔细的看他，咦 !! 他不是那个逃犯黄二吗？\n"
	);
        set("unit","个");
        set( "inquiry", ([ "jail" : 
@JAIL
我是从镇上的牢里逃出来的，我真的是冤枉的 !! 求求你不要再把我
抓回去 !! 我们在床底下挖了一条地道，本来要通到城外的，没想到却通到一个
很大的院落，我也不知道那是哪里，只听见有人说著什麽月神、宫殿的，後来下
起大雨，地道塌了，我趁乱逃了出来，就一直躲在这里。
我真的是无辜的，请你不要和别人一样冤枉我。
JAIL
, "jor" : 
@PARTNER
左无心？你是说那个江洋大盗吗？我根本不认识他，他也不管我的死
活，一出地道就把我一个人丢下了，不过他因为被刑求，所以双腿不怎麽灵活，
要不是需要我扶他，他根本不会理我。他曾经问我镇上最好的医生是谁，我想他
可能去医腿了 !! 我把我知道的都告诉你了，求求你饶了我吧 !!
PARTNER
]));
        set( "gender", "male" );
        set( "race", "human" );
        set_natural_armor( 40, 10 );
	set_natural_weapon(11,6,14);

	set( "chat_chance", 20 );
        set ("chat_output",({
                "那人哀求道：「求求你不要把我抓回牢(jail)里去 !!」。\n",
	}) );
#include <replace_mob.h>
}
