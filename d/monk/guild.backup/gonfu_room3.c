#include "saulin_temple.h" 

inherit "/d/monk/guild/train_gonfu.c";
inherit ROOM;

void create()
{
	room::create();
	set_short("A protect gonfu room", "少林武学精武房");
	set_long( @LONG_DESCRIPTION
NEED TRANSLATE HERE.
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
这里是少林寺学习各种不同刀棍护身武学的练功\房，大部份常见的的少林武功\
秘笈都放在这里。一些特殊的武功\秘笈则被放在楼上的少林七十二绝技房及藏经阁
在你面前是一堆泛黄的卷轴(scroll)，你可以根据自己的刀棍武学造诣选择你能够
学习的武功\，然後在此处训练 (train)，角落有一个注意须知(note)你不妨先看看 
往南可以回到罗汉堂，向上则通内功\心法房。
C_LONG_DESCRIPTION
	);

    set("c_item_desc",([
         "note":@BOOK
少林武学是用来在战斗中攻击敌人或防护自己的功\夫。使用方法是 

                  eungon [功\夫名称] 
       然後再     k      [怪物名字]

少林武学强弱和熟练度有很大的关系，所以要多多使用以增加熟练度。功\夫在精不  
在多，所以你不一定要每一样都学。熟练度为零的效果和一百时有所差异，不要忘 
记当熟练经验值够了时要去训练提升武学境界。
(攻击，医疗和护体的功\夫一次只能三选一用。)   
BOOK
	]));         

    set( "no_monster", 1);
	set( "light", 1 );
	set( "exits", ([ 
		"up"    : SAULIN"inner_room",
 		"south" : SAULIN"monk_guild" ]) );
                 
	set( "item_func", ([
		"scroll": "view_catalog" ]) );

	set_gonfu_type("general");
	set_gonfus( ([
        "tai-zuo"  : ({ "martial-art", 15,   800 }),
        "wu-sur"   : ({ "martial-art", 30,  2200 }),
	"da-mo"    : ({ "martial-art", 30,  2000 }),
	"fu-mo"    : ({ "martial-art", 60, 10000 }),
        "bolo-mi"  : ({ "martial-art", 25,  1000 }),
	"chu-han"  : ({ "martial-art", 85, 21000 }),
        "gi-mei"   : ({ "martial-art", 65,  8000 }), 
	]) );

	reset();
}
