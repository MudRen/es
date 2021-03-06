// File: /d/eastland/goomay/mroad1.c
// create by : Ruby the little wizard from 5/6/1994

#include <goomay.h>
inherit ROOM;
string *c_msg = ({
"墙上涂满了乱七八糟的字，你根本分不清楚到底在写些什麽。\n",
"墙壁的左下角画著一把小雨伞，伞下写著段誉、王语嫣..\n",
"墙壁的最上面被人用指力刻著：飞天猫第三次大胜狐狸狗留念。\n",
});

void create()
{
	::create();
	set_short("青石板大道");
	set_long( @LONG_DESCRIPTION
你走在古梅镇平坦的青石大道上，光洁的青石板显示著这个城镇的活力，
伴随在你身边的是小贩的吆喝声、马车的辚辚声还有偶而疾驰而过的骏马，那
是一些想要成名的武林人物，古梅镇的西风尘沙中，不知埋葬了多少年轻人的
梦想。街道向东西延伸而去，北方是闻名於世的武斗大会场，但门口却不在这
里，在那堵高墙上被涂满了乱七八糟的字。
LONG_DESCRIPTION
	);
        set("c_item_desc",(["wall":"@@look_wall"
                  ]));

        set_outside( "eastland" );
	set( "exits", ([ 
                "east" : Goomay"col24",
		"west" : Goomay"row25",
	]) );
        set( "objects", ([
                "woman1" : Mob"visitor",
                "woman2" : Mob"visitor",
        ]) );

	reset();
}

string look_wall()
{
	return c_msg[random(sizeof(c_msg))];
}
