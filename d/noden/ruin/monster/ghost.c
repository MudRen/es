// ghost gardener

#include "../lilia.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(1);
    set_name("ghost", "鬼魂");
    set_short("鬼魂");
    set_long(@C_LONG
这团模糊的白影，手上似乎拿著小水瓢和花剪，它生前或许就是这儿的园
丁吧！究竟是什麽原因让他在这里逗留没到奈何桥去报到呢？或许静心观察一
下会有些收获也说不定。
C_LONG
	    );
    set("chat_chance", 15);
    set("chat_output", ({"鬼魂说：前头是受诅咒的死亡迷宫，还是快回头吧!\n"}));
    set("no_attack", 1);
    set("gender", "male");
    set("race", "undead");
    set("unit", "位");
}
 

