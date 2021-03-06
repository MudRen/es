#include "../almuhara.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(5);
    set_name("Tomb Thief","盗墓贼");
    add ("id", ({ "thief"}) );
    set_short( "盗墓贼");
    set_long(
@C_LONG
一个盗墓贼，他正在找寻陵墓的入口。
C_LONG
	);
    set("alignment",-300);
    set( "gender", "male" );
    set( "race", "human");
    set( "unit", "个" );
    set_perm_stat( "str", 10);
    set_perm_stat( "dex", 10);
	set_skill("dagger",40);
    set ("max_hp",150);
    set ("max_sp",0);
    set ("hit_points",150);
    set ("spell_points",0);
    set ("wealth", ([ "gold":10]) );
    set_natural_weapon(20,5,13);
    set_natural_armor(40,5);
    set ("weight", 350);
    set("chat_chance",15);
    set("chat_output", ({
        "盗墓贼说道: 听说地底广场中央有机关可以找到陵墓之门.....\n",
        "盗墓贼说道: 听说地底广场中央有机关可以找到陵墓之门.....\n",
        "盗墓贼自言自语: 我一定要找到那颗宝珠。\n",
    	"盗墓贼邪笑著对你说道: 敢情阁下跟俺做的是同样的无本生意 ??\n",
    	"盗墓贼抓抓他的头，似乎在思考什麽。\n" }) );
    set("att_chat_output",({   
        "那贼喊道: 你不想活了，竟敢跟我抢地盘 ?\n"
       }) );
    set( "moving", 1 );
    set( "speed", 40 );
    set( "patrol", ({ "east", "east", "north", "north", "north", "east",
		"north", "north", "east", "east" }) );
    wield_weapon(WEAPONS"/dagger1");
}


