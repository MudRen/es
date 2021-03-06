#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short("湖中");
	set_long( @C_LONG_DESCRIPTION
这里是湖中的深水区域，除了打鱼的鱼夫偶而会来到此处外，一般的冒险者由
於游泳技术不佳，很少来到此处。形形色色的鱼儿，因为没有人为的干扰，正在水
中快乐的游来游去。
C_LONG_DESCRIPTION
	);

	set_outside("eastland");
	set( "exits", ([ 
		"down" : TROOM"underwater1", 
		"south" : TROOM"shallow21",
		"east" : TROOM"deep2" ]) );
	set( "pre_exit_func",([
	        "east":"check_deep",
	        "south":"check_shallow"
	        ]));
	set( "objects",([
	        "fish": TMONSTER"fish1"]));
	reset();
}
int check_deep()
{    
    if ((int)this_player()->query_skill("swimming")-random(15)<40){
    write (
    "你努力地想要游到别处，但是身子却不听使唤的向下沉去.......\n");
    this_player()->move_player(TROOM"underwater1","SNEAK");
  return 1;
  }
    else return 0;
}
int check_shallow()
{
    if ((int)this_player()->query_skill("swimming")-random(5)<13){
    write (
    "你努力的想游到别处，但你发现身体一动也不动.....\n");
  return 1;
    }
    else return 0;
}
