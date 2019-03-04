#include <mudlib.h>
#include <stats.h>

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create()
{
        
	set_name("sausage","『一口香肠』");
	add( "id" , ({ "sausage" }) );
   set_short("『一口香肠』");
   set_long(@C_LONG
一串串烤得香香的香肠,引起你食指大动。
C_LONG
	);
   	set("unit","个");
        set("weight", 15);
   	set("value",({ 300, "silver" }) );
}

int eat_food(string arg)
{
        
    if( !arg ||( arg != "sausage") ) 
        return notify_fail("你要吃啥东东?\n");
    tell_room( environment(this_player()),this_player()->query("c_name")+
        "狼吞虎□地吃下了一个『一口香肠』,好像三天没吃东西的样子...\n", 
         this_player());
    tell_object( this_player(),
        "你狼吞虎□地吃下了一个『一口香肠』,看来你是饿了～～\n");
    this_player()->receive_healing( 15+random(5) );
    remove();
    return 1;
}
