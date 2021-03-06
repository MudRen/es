// min6.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("神殿内厅");
    set_long(@C_LONG
你现在在神殿的内厅里，四周一片空空汤汤，只有素净的墙壁和天
花板静静地立著。凛冽的寒风由四面八方吹来，令你觉得有些寒冷。「
哪来的这麽大风？」你的心中不由得纳闷著。  
C_LONG
    );
    set("item_desc", ([
	"plate" : "一块小小的木牌，上头写著：「风神力．气盾之壁」\n",
	"button" : "红黄蓝三种颜色的按钮。\n"
	]) );
	
    set("exits", ([
	"north" : AREA"min7",
	"south" : AREA"min5"
	]) );
    set("pre_exit_func", ([ "north" : "exits_open" ]) );

    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_push", "push");
}

int exits_open()
{
    if (this_player()->query_temp("lilia_pass") == 3)
    {
	write("你身体里忽然涌现一股神奇的力量，你轻易地穿过气盾墙。\n");
    	return 0;
    }
    else
    {
	write("一道无形的阻力挡住你的去向。\n");
	return 1;
    }
}

int to_search(string s)
{
    if (!s)
    {
	write("你找了又找，发现地上似乎有块小木牌 (plate)。\n");
	return 1;
    }
    else if (s == "plate")
    {
	write("小木牌上面有三个按钮 (button)。\n");
	return 1;
    }
    else if (s == "button")
    {
	write("这三个按钮除了颜色不同，其他大小形状都一样。\n");
	return 1;
    }
    else
	return notify_fail("你想找什麽？这里好像没什麽东西嘛 ...\n");
}

int to_push(string s)
{
    string color;
    object p;
    int order;

    if (!s)
    {
	return notify_fail("你想按什麽？\n");
    }

    sscanf(s, "%s button", color);
    p = this_player();
    order = p->query_temp("lilia_pass");

    switch (color)
    {
	case "red": 
	    if (order == 4)
		p->set_temp("lilia_pass", 5);
	    else
		p->set_temp("lilia_pass", 2);
	    break;
	
	case "blue":
	    p->set_temp("lilia_pass", 4);
	    break;

	case "yellow":
	    if (order == 5)
		p->set_temp("lilia_pass", 3);
	    else
		p->set_temp("lilia_pass", 2);
	    break;
	default:
	    return notify_fail("你想按什麽颜色的按钮?\n");
     }

     write("你按下按钮，但是似乎什麽事都没有发生 ...\n");
     return 1;
}
        
