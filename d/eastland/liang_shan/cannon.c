#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "神火炮营" );
	set_long(
	"你来到山顶上的一片空旷平地，这里就是梁山泊著名的神火炮营，由轰天雷\n"
	"凌振指挥。梁山泊之所以能够履败官兵，除了勇将与天险之外，神火炮营也是其\n"
	"中一个重要的因素。这些火炮(cannon)现在正罗列在崖边，射程涵盖\了从大石桥\n"
	"到幽国城的广大土地。\n"  
	);
	set_outside("eastland");
        set("c_item_desc",(["cannon":
"这是用上好的青铜铸成的巨型火炮，是利用默尔斯人所发现的神奇爆炸粉来发射\n"
"炮弹的，炮身中空，足足有两个人那麽长，外面刻著许\多奇怪的符号。\n"
            ]));        
        set( "exits", ([
                "down" : TROOM"yard1",
                "north" : TROOM"gate3" 
        ]) );
        set( "objects",([
                "ling":TMONSTER"lingchen",
                ]));
        reset();
}
int clean_up() { return 0; }