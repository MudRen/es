#include <almuhara.h>

inherit ROOM;

void create()
{
        ::create();
        set_short( "铜人阵中" );
        set_long(
@C_LONG
你进入了一个较小的石室，环顾四周空无一物，只有在墙上挂了张
卷轴(scroll)，以及旁边有个茶壶(teapot)。看来这儿是用来让闯关的
人稍做休息之用，在经历了刚才的大战後，你不禁感激当初做此设计的
人。
C_LONG
        );


        set( "light",1 );
        set( "exits", ([
                "north" : BRASS"/zeng7"
        ]) );
        set( "post_exit_func", ([
        	"north" : "post_north" ]) );
        add( "item_desc", ([
        	"scroll" :
"哇 !! 你已经通过前三关了，相当厉害 !! 
下一关是在考验你的七十二绝技的\功\力，请先准备好再往前走。\n",
		"teapot" :
"一个小小的茶壶，也\许\你可以喝喝水(drink water)，休息一下。\n"
	]) );  
        reset();
}

void init()
{
	add_action("do_knock","knock");
	add_action("do_quit","quit");
	add_action("do_auction","auction");
	add_action("do_drink","drink");
}

int do_knock(string str)
{
	object obj,ob1;
	obj = this_player();
	
	if( !str || str == "" ) return 0;
	if( str == "wall" ) {
		tell_object(obj,
			"突然两个红衣罗汉自墙中暗门走出，将你抬了出去。\n" );
		ob1=find_object_or_load(SAULIN"/entrance");
		tell_room(ob1,
			sprintf("你看到两个红衣罗汉将%s像抬猪公一样抬了出来。\n",
				obj->query("c_name") ) );
		obj->add("monk_score",-100);
		obj->delete_temp("drink_already");
		obj->move_player(SAULIN"/entrance","SNEAK");
		ob1->set("enter",0);
		return 1; }
	else return 0;
}
		
int do_quit()
{
	object obj,ob1;
	obj = this_player();
	
	tell_object(obj,
			"突然两个红衣罗汉自墙中暗门走出，将你抬了出去。\n" );
	ob1=find_object_or_load(SAULIN"/entrance");
	tell_room(ob1,
		sprintf("你看到两个红衣罗汉将%s像抬猪公一样抬了出来。\n",
			obj->query("c_name") ) );
		obj->add("monk_score",-100);
		obj->delete_temp("drink_already");
		obj->move_player(SAULIN"/entrance","SNEAK");
		ob1->set("enter",0);
		return 1;
}

int do_drink(string str)
{
	object obj;
	obj = this_player();
	
	if(!str || str == "") return 0;
	if( str == "water" ) {
		if( !obj->query_temp("drink_already") ) {
			tell_object(obj,
				"喝了一口水，你觉得全身一阵清凉。\n" );
			obj->add("medication_resistance",-300);
			obj->set_temp("drink_already",1);
			return 1; }
		tell_object(obj,
			"再喝一口水，你觉得好像没什麽差别了。\n" );
		return 1; }
	else return 0;
}

int post_north()
{
	this_player()->delete_temp("drink_already");
}

int do_auction()
{
	return 1;
}