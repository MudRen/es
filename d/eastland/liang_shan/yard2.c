#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "庭院" );
	set_long(
	"这是一个小小的庭院，安静而且典雅，浓荫如伞，木叶之外有蝉声摇曳，\n"
	"却显得天地更为寂静，红尘中的喧闹烦嚣，似已久未入庭院。北边有一个小\n"
	"小的建筑。西边有一座精致的竹制凉亭(shed)。\n"
	);
	set_outside("eastland");
	set( "light",1 );
        set( "no_monster",1);
        set( "c_item_desc",(["shed":
        "这是一座精巧的小凉亭，完全用青竹制成，亭内有一个书生打扮的人，正\n"
        "低头不知在观看什麽? 也许\你可以进去(enter)看看....\n"
        ]));
        set( "exits", ([
                "north"  : TROOM"bed6",
                "east" : TROOM"path6",
        ]) );
        reset();
}
void init()
{
add_action("do_pass","enter");
}
int do_pass(string arg)
{
 if ( !arg || arg != "shed")
    return notify_fail(
    "你想要进去那儿?\n");
    write (
    "你顺著小小的阶梯，缓缓步入了凉亭\n");
    tell_room(this_object(),
	"你看到"+this_player()->query("c_name")+"信步走进了凉亭内。\n",
    this_player());
    this_player()->move_player(TROOM"shed","SNEAK");
   return 1;
}
int clean_up() { return 0; }    
