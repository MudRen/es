#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "drink_tea", "drink" );
}

void create()
{
	set_name("diet tea","减肥茶");
	add( "id" , ({ "tea" }) );
	set_short("diet tea" , "减肥茶");
	set_long(".." , 
		"这是一杯奇特的茶，碧绿的茶水发散出一阵阵浓郁的芬芳香气，\n"
		"闻之使你精神大振。\n"
	);
   	set("unit","杯");
   	set("weight", 20);
   	set("value",({ 10000, "copper" }) );
}

int drink_tea(string arg)
{
	if( !arg || arg != "tea" ) return 0;
	else {write( "你慢慢的品尝这杯减肥茶，忽然一阵奇怪的凉意从丹田开始，游走全身...:)\n" 
		);
		tell_room( environment(this_player()), (
			this_player()->query("c_cap_name")+"喝下一杯减肥茶，然後露出奇怪的表情"
			"，你注意到他慢慢的瘦了下来\n" ), this_player()
		);
		this_player()->receive_healing( -15+random(5) );
	}
	remove();
	return 1;
}

