#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create(){

        set_name( "banana", "香蕉" );
        add( "id", ({ "banana" }) );
        set_short( "香蕉" );
        set_long(@C_LONG
这是一条香蕉，看起来十分新鲜美味，吃(eat)了它以後想必
能提振一些精神吧 !!
C_LONG
		);
   		set("unit","条");
   		set("weight", 5);
   		set("value",({40, "silver"}) );
}

int eat_food(string arg)
{
	if( !arg || arg != "banana") return 0;
	write( 
		"你狼吞虎□地吃掉一条香蕉，觉得齿颊留香...:)\n"
	);
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"三两下就吃掉一条香蕉，你都看呆了...\n"
		, this_player()
	);
	this_player()->receive_healing(5);
	remove();
	return 1;
}
