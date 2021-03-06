#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "凉亭" );
	set_long(
	"这是一座精巧的凉亭，完全由青竹制成，虽然不是说雕梁画栋，但纯朴\n"
	"的装饰却更能与自然融为一体，凉亭中央放著一张棋盘(chess)，□杀的正\n"
	"激烈，一名中年文士正专心的研究棋局，完全没注意到你的到来。\n"
	);
	set_outside("eastland");
	set( "light",1 );
        set( "no_monster",1);
        set( "c_item_desc", (["chess":
        "你看到一张青石所制的围棋棋盘，上面有一场未决生死的棋局，你的好奇心\n"
        "促使你仔细的看著(behold)这棋局。\n"
        ]));
        set( "exits", ([
                "out" : TROOM"yard2",
        ]) );
        set( "objects",([
                "wuyong" : TMONSTER"wuyong",
        ]));        
        reset();
}
void init()
{
    add_action("do_behold","behold");
}
int recover(object player)
{
player->set_temp("block_command",0);
write (
"经过好久好久，你好不容易恢复神志，决定放下屠刀，金盆洗手，去当巫师去吧:D\n");
return 1;
}  
int do_behold(string arg)
{
if (!arg ||arg !="chess")
return notify_fail(
"看什麽?\n");
write (
"你仔细的看著这棋局，只见死中有活，劫中有劫，错综复杂，不知胜败归於何方?\n"
"你看的眼花撩乱，冷汗直流...................\n\n\n"
"你又想起你这一生的杀伐罪业，恩怨情仇，突然大喊一声，昏死在地。\n");
this_player()->set_temp("block_command",1);
this_player()->set_explore("eastland#24");
call_out("recover",40,this_player());
return 1;
}
int clean_up() { return 0; }
