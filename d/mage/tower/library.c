//#pragma save_binary

#include "/d/mage/mage.h"

inherit ROOM;

void create()
{
	object master;
	::create();
	set_short("The Magic Library", "魔法图书馆");
	set_long( @C_LONG_DESCRIPTION
这里是摩亚达城最古老的魔法图书馆，各式各样的魔法经典语法术卷轴被整齐
地收藏在好几排三、四个人高的书架(bookrack)上，这里目前是归魔法师公会管理
，所有的魔法知识也都被分门别类放在几个收藏室内，在你的东边是收藏元素魔法
的图书室，西边是集黑魔法之大成的卷轴室，往北的房间主要是收集一些冷僻的魔
法书籍，中央的一道螺旋梯通往三楼的高级魔法能源研究室。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "no_monster", 1);
	set( "c_item_desc", ([ 
		"bookrack" : "十分老旧的木书架，放了一些残破的卷轴(scroll)，上面满是灰尘。\n" ,
		"scroll" : "@@look_scroll"]) );
	set( "exits", ([ 
		"north" : MAGE"misc_lib", 
		"west"  : MAGE"black_lib", 
		"down"  : MAGE"mage_guild", 
		"east"  : MAGE"element_lib",
		"south" : MAGE"spell_lab",
		 "up"   : MAGE"energy_lab", 
    ]) );
	master = new( "/d/mage/tower/monsters/patolas");
	master->move( this_object() );
	reset();
}

string look_scroll()
{
	if (!present("patolas") ) return "一些残破不全的卷轴，上面写些什麽已经无法辨认了。\n";
return(@DESC
一些残破不全的卷轴，上面写些什麽已经无法辨认了。

帕多拉斯叹了口气，说：公会里本来存有很多记载高等法术的卷轴，但是
有一次公会被入侵，魔法卷轴被掠夺一空，只留下这些残破不堪的卷轴。
经过动员全魔法公会的成员多年来四处明察暗访，终於查出其中一些卷轴
的下落。

	火球术[7] : 地精大长老欧瑞安。需元素魔法等级50以上方能使用。
	幻雷术[4] : 大国师孝光。需黑魔法等级50以上方能使用。
	以太之箭[8] : 精灵王。需黑魔法等级50以上方能使用。

因著某个不知名的原因，以上这三种攻击魔法只能择一学之。
   
	星空之门 : 矮人国王莫拉德五世。需杂项魔法等级50及探险度60%
		以上方能使用。
DESC
);
}

int clean_up() { return 0; }
