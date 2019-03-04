#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create()
{
	set_name("dry meat","咸肉乾");
	add( "id" , ({ "meat" }) );
	set_short("dry meat" , "咸肉乾");
	set_long( 
		"这是一块不知什麽东西作成的肉乾，上面有著一粒一粒的食盐结\n"
		"晶，可想而知滋味并不是很好，但可能可以保存很久。\n"
	);
   	set("heal",1);
   	set("unit","块");
   	set("weight", 10);
   	set("value",({ 1, "silver" }) );
}
int eat_food(string arg)
{
     object me;
     int num1,num2;
		me = this_player();
		if( !arg || arg != "meat" ) return notify_fail("吃什麽?\n");
		write( "你慢慢啃著这块肉乾，哇，真咸，但是至少还能用来填肚子..\n" );
                tell_room( environment(me),
                "你看到"+me->query("c_name")+"用力的啃著一块肉乾"
                "，一边露出奇怪的表情...\n" , this_player());
                num1 = query("heal");
                num2 = num1/2+10;
		me->receive_healing(num1);
	        me->add("talk_points",-num2);
// Eat too much meat tp <0 will sick
// add by Iris@ES Feb 6 1996	        
	if (me->query("talk_points")<0) {
		write("或许是肉乾吃多火气大, 你觉得身体不太舒服...\n");
		(CONDITION_PREFIX+"sick")->apply_effect(me,3,2,2);
	}		        
       if ( query("rotten") != 1 ) {
        remove();
        return 1;
        }
       write( "奇怪，可能是做的时候不太卫生，你感觉有点不舒服...\n");
       (CONDITION_PREFIX + "weak")->apply_effect(me,6,5);
	remove();
	return 1;
}

