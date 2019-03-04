#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit OBJECT;

void init()
{
	add_action( "smell_food", "smell" );
        add_action( "hook_hook", "tie");
}

void create()
{
	set_name("meat","臭鱼烂虾的肉");
	add( "id" , ({ "meat","fish" }) );
   set_short("臭鱼烂虾的肉");
   set_long( "　　这些肉原来是些什麽已经没人知道了，但从它们的来源来看大概\n"
             "是一些鱼虾之类，虽然它们不时发出刺鼻的臭味，你还是忍不住地把\n"
             "它放在鼻子前闻一闻(smell)。\n" );
   	set("unit","块");
   	set("weight", 5);
}

int smell_food(string arg)
{
object holder;	

       if( !(holder = environment(this_object())) || !living(holder) ) return 0;
       
       if( !arg || arg != "meat" ) return 0;
       write("\n啊，真是臭啊.....\n");
       (CONDITION_PREFIX + "weak")->apply_effect(holder,4,4);
	return 1;
}

 int hook_hook(string arg,object me)
 {
 int i,n;
 object ob;
 
 if (!arg || arg != "hook" )
 return notify_fail(
 "想穿这些烂肉在什麽上?\n" );
 if (!(int)this_player()->query_temp("can_fish")==1 )  {
 write(
 "\n你把臭鱼烂虾的肉穿在钓钩上...\n");
 this_player()->set_temp("can_fish",1);
 remove();
 return 1;
}
 else 
 write(
 "\n钓钩上已经穿好了钓饵.....\n");
 return 1;
}