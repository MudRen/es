//#pragma save_binary

#include <mudlib.h>
#include <daemons.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "任务殿堂" );
	set_long(@C_LONG
你现在正站在一间充满著祥和气氛的大厅之中，这个大厅是用某种白
中带著淡蓝色纹路的石材建成的，一些绿色的植物和漂亮的花卉装饰著大
厅四周的圆柱。四面的墙壁上雕刻著极为优美的图画。而大厅的中央有著
一个很耀眼的水晶球(crystal ball)悬浮於空中。有一个阶梯通向上方的
冒险者公会。你可以由那里开始你的冒险旅程。
C_LONG
	);
	
	set("item_desc",([
	    "crystalball":"@@c_quests_hint",
	    "ball":"@@c_quests_hint",
	]) );
	set( "light", 1 );
	set( "exits", ([
		"up"    : "/d/adventurer/hall/adv_guild",
	    "south" : "/d/noden/farwind/area_room",
       "north" : "/d/noden/farwind/bugroom",
	]) );
	set( "pre_exit_func", ([
        "south" : "wiz_limit"
    ]) );
/*
    set( "objects", ([
    	"explore_list" : "d/noden/farwind/items/explore_list",
   	]) );
*/
   	reset();
}

int wiz_limit()
{
    if( !wizardp(this_player()) ) {
        	write("对不起，只有巫师才能进去。\n");
        return 1;
    }
    return 0;
}

void init()
{
     add_action("to_listen","listen");
}

string c_quests_hint()
{
   "/std/fun/quests_hint"->show_all_quests();
   return "\n";
}

int to_listen(string arg)     
{
    mixed num;
    
    if( !arg ) {
       write("你可以使用 listen ?(number) 获得更多的资料.\n");       
       return 1;
    } else if( sscanf(arg,"%d",num) == 1 ) {
        if( num <= (int)QUEST_D->query_quests_number() )
        return "/std/fun/quests_hint"->show_quest(num); 
    }
    write("你可以使用 listen ?(number) 获得更多的资料.\n");
    return 1;                 
}

/*
void reset()
{
	int	i;
	object	*all_ppl;

	::reset();
	all_ppl = users();
	i = sizeof(all_ppl) - 1;
	while ( i >= 0 ) {
		call_other(	find_object_or_load("/d/noden/farwind/items/top_explore"),
					"log_player", all_ppl[i]);
		i--;
	}
}
*/
