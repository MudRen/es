#include <mudlib.h>
#include <stats.h>
#include <conditions.h>
#define FRESH_TIME 60

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create()
{
	set_name("fish meat","黄金梦幻鲤鱼的肉");
	add( "id" , ({ "meat","fish" }) );
   set_short("黄金梦幻鲤鱼的肉");
   set_long( "外皮闪耀著美丽的金色光芒，内层是半透明的鱼肉，据说是\n"
             "人间的珍味。\n" );
   	set("unit","块");
   	set("weight", 15);
	call_out("not_fresh", FRESH_TIME, this_object() );
	set("is_fresh",1);
}

int eat_food(string arg)
{
	if( !arg || arg != "fish" ) return 0;
	if( !query("is_fresh") ) {
        write("你吃掉一块腐烂了的鱼肉。\n");
        tell_room( environment(this_player()),
           this_player()->query("c_name")+"吃掉一块腐坏了的鱼肉。\n"
                   , this_player()
		);
       (CONDITION_PREFIX + "sick")->apply_effect(this_player(),15,2,5);
	} else {
        write(
                "你愉快地吃掉这一块生鱼肉, 清甜的滋味在口中慢慢扩散....:)\n" );
        tell_room( environment(this_player()),
                     this_player()->query("c_name")+"吃掉了一块生鱼肉，看起"
                "来精神大振...\n", this_player()
		);
           this_player()->receive_healing( 40+random(10) );
	}
	remove();
	return 1;
}

void not_fresh(object what)
{
	object owner;
	owner = environment(what);
	what->set ("value", ({ 1, "silver" }));
   what->set_short( "腐坏的鱼肉" );
   what->set_long( "这块鱼肉已经腐坏了，发出一股难闻的气味。\n" );
	what->set("is_fresh",0);
   if ( !owner ) { remove(); return ; }
   if( !living(owner) ) { remove() ; return; }
   write(
        "你闻到一股臭味传来, 好像是什麽东西坏了的样子。\n"
	);
}
