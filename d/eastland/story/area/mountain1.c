#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("山顶");
	set_long( @LONG
在这山顶北方的远处是层峦叠峰，好似一幕幕的绿布不住往天际延伸，南边则
是一断崖，白茫茫的一片深不见底。头上的白云离顶只不过尺许高度，一抹抹如条
素色的被子，像要压将下来。往西一眺，不远处有湾白滩，在阳光照射下白星点点
；往北俯视，与对山之间衔接著一个溪流，急湍澎湃，「刷刷」有声，不知高度若
何，否则大可一游而尽兴。东边蜿延著崎岖的山路，西边的下面是块山壁，另外在
路旁有块石碑(stone)。　
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	      "east" : SAREA"mountain2",
        ]) );
	set("c_item_desc",([
	  "stone":@LONG
石碑上写著：
　　　　　　仁人君子请爱惜自己的生命，不要轻易往底下的溪谷跳下去( jump down ) 
           ，以免发生危险。　　
LONG	  
	]) );
	reset();
}
void init()
{
   add_action("do_jump","jump");
}	
int do_jump(string arg)
{
    if ( !arg || arg!="down" ) return 0;
    write(@LONG
    
你往北边的溪谷一跳，身子落下数百丈，迎面的风压得你喘不过
气来，令你无法做任何动作．．

LONG
    );
    this_player()->set_temp("block_command",1);
    call_out("back",5,this_player());
    return 1;
}
void back(object player)
{
    write(@LONG

眼看你就要摔的粉身碎骨，忽然，空气中有一无形的力量把你托
了上去使你安全到达地面丝毫无损！！

LONG
    );    
    player->delete_temp("block_command");
    player->move_player(SAREA"bottom2",({
        "%s往北边的溪谷一跳。\n",
        "%s从高空中落了下来。\n"}),"");
    return ;
}
