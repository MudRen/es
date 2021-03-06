#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "了望台" );
	set_long(
	"这里是梁山泊山寨的了望台，用粗大的桧木架成，虽然强风不断，\n"
	"站在上面仍然如履平地．角落放著一台千里镜(telescope)．\n"
	  
	);
	set_outside("eastland");
	set( "light",1 );
        set("c_item_desc",(["telescope":
"这是默尔斯帝国进贡的千里镜，透过它可看到很远的地方．最近被梁\n"
"山泊的好汉们抢来，目前它正对著幽国城的方向以便监视官兵动静．\n"
"也许你可以试著去使用(use)它．\n"            
            ]));        
        set( "exits", ([
                "down" : TROOM"wall8"
        ]) );
        set( "objects",([
                "lu":TMONSTER"lu",
                "bandit":TMONSTER"small_bandit",
                "captain":TMONSTER"captain"
                ]));
        reset();
}
void init()
{
     add_action("do_use","use");
}
int do_use(string arg)
{
 if ( !arg || arg != "telescope")
    return notify_fail(
    "用什麽?\n");
    write (
    "你将眼睛凑近千里镜，幽国城繁华的市街浮现於你眼前．\n");
    tell_room(this_object(),
    "你看到"+this_player()->query("c_cap_name")+ "使用千里镜，并且露出不可思议的表情\n" ,
    this_player());
return 1;
}
int clean_up() { return 0; }    