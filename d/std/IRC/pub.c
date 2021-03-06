// hardcoded pub for IRC.. I'll make it more flexible when I finish
// the vending machine....
// Elon@Eastern.Stories Sat  08-13-94
#include <irc.h>
#include <move.h>
 
inherit ROOM;
 
void create()
{
	::create();
	set("light", 1);
    set_short( "Ted\'s Corner","泰德的角落" );
    set_long(
@LONG
The room was lit dimly enough to be cozy, but not so dark as
to be scary. Smoky oil lamps hung from the ceiling, and there
is a menu pinned on the south wall.
 
LONG
,
@CLONG
这是一间有点暗却又不太暗的小店. 天花板上吊著一个黑黝黝的油灯.
南边墙上钉了一个目录 (menu).
 
CLONG
    );
    set("objects", ([
    "ted" : RM+"ted.c",
    "recycle" : RM+"recycle.c",
    ]) );
reset();
    set("exits", ([
    "north"  : RM+"lobby",
                ]) );
	set("item_desc",([
    "menu":
@MENU
Ted\'s Corner -- The ONLY place you can get drink in this world.
----------------------------------------------------------------
Coke               50 silvers
Pepsi              50 silvers
 
Vodka              75 silvers
 
Water (CLEAR)      10 silvers
Use order <drink> to order drinks from Ted.
(more drinks will be added in the future, post to board for ideas.)
MENU
                ]) );
    set("c_item_desc",([
    "menu":
@CMENU
泰德的角落 -- 附近唯一有卖饮料的地方.
----------------------------------------------------------------
可口可乐 (Coke)    50 silvers
百事可乐 (Pepsi)   50 silvers
 
伏特加 (Vodka)     75 silvers
 
水 (Water)         10 silvers
----------------------------------------------------------------
请备妥零钱直接向泰德 order.
(新饮料会陆续推出, 如有建议请 post)
CMENU
                ]) );
}
 
void init()
{
    add_action("order_drink","order");
}
 
int order_drink(string str)
{
    string name;
    object ob;
    mixed *value;
    if (!str || str=="") {
        return notify_fail("Syntax: order <drink_name>\n");
    }
    switch (str) {
        case "coke" : name="coke";
        break;
        case "pepsi" : name="pepsi";
        break;
        case "vodka" : name="vodka";
        break;
        case "water" : name="water";
        break;
        default: {
            write(can_read_chinese()?
            "Chinese message here.....\n":
            "Ted shakes his head, and said, we don't have this drink.\n");
            return 1;
        }
    }
    ob = new(RM+name);
    value=ob->query("value");
    if (ob->move(this_player())!=MOVE_OK) {
        ob->remove();
        write(can_read_chinese()?
        "泰德告诉你: 你拿不动这个饮料.\n":
        "Ted tells you: Your hands are too full to take this.\n");
        return 1;
    }
    if (!this_player()->debit(value[1],value[0])) {
        write(can_read_chinese()?
        "泰德瞪你一眼, 冷冷地说: 没钱就不要来.\n":
        "Ted stares at you, and says, Hey man, you can't afford to buy this.\n");
        ob->remove();
        return 1;
    }
    tell_room(environment(this_player()),({
        "Ted says out loud: One order of "+name+" coming up "+
        "for "+this_player()->query("cap_name")+".\n",
        "泰德大声地说: "+this_player()->query("c_name")+"点了一"+
        ob->query("unit")+ob->query("c_short")+".\n",
        }), ({this_object(),this_player()}));
    write(can_read_chinese()?
        "泰德走近你, 递给你一"+ob->query("unit")+ob->query("c_short")+".\n":
        "Ted approaches you and says: Here you go. One "+
        ob->query("e_unit")+" of "+name+".\n");
    return 1;
}
 
