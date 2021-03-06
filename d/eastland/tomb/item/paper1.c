#include "../almuhara.h"

inherit OBJECT;

void create()
{
	set_name("paper","发黄的羊皮纸");
	set_short("发黄的羊皮纸");
	set_long(
		"一张发黄的羊皮纸，上面写著满满的字。\n"
	);
	set("no_sale",1);
	set( "unit", "张");
	set("weight", 5);
	set("value", ({ 5, "silver" }));
}

void init()
{
	add_action("read_paper","read");
}

int read_paper(string str)
{
    object ob;
    if ( !str || str != "paper" ) return 0;
    else {
      ob = environment(this_object());
      if ( ob != this_player() ) 
        return 0;
      else 
        {
          write("有缘人：\n"
		"我是负责建筑此地的工匠首领  陈彬。当你见到此封信时，可能已是数百\n"
		"年後了，但我仍然要把一切写下，告诉後人.......\n"
		"当年大国师  孝光发现了此钟天地之灵气的宝穴，即禀告皇上。而皇上亦\n"
		"下令在此建筑陵墓，以求我国运昌隆、绵延不绝。大家知道这是与国运有\n"
		"关，莫不尽心尽力，以期将此处建设完美。谁知就在完工在即之时，竟有\n"
		"一近侍向皇上进谗，欲杀尽建筑此地的工匠，幸好有人事先通知我，我方\n"
		"能辟此小室避祸，惜我身中数创，仍逃不过一死.........\n\n"
		"我死於此，天意乎？  但求有缘人能将我身躯安葬，使我死後无憾。\n\n\n"
		"					赛鲁班  陈彬 绝笔\n" );
          return 1;      
        }
    }
}
