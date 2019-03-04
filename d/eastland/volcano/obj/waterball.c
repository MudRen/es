#include "../oldcat.h"

inherit OBJECT;

void init()
{
	add_action( "hold_ball", "hold" );
}

void create()
{
        set_name( "prevent_water ball", "辟水珠" );
        add( "id", ({ "ball" }) );
        set_short( "辟水珠" );
        set_long(
@LONG
一颗用独角兽的角磨制的辟水珠，据说只要手握著它，就可将水分出一条路来。
LONG
		);
   		set("unit","颗");
   		set("weight", 10);
   		set("value",({10, "silver"}) );
                set("no_sale", 1 );
}

int hold_ball(string arg)
{
    if( !arg || arg != "ball" ) return 0;
    if ((int)environment(this_player())->query("in_well")==1 ) {
    	tell_object(this_player(),
    	    "你手握辟水珠，只见眼前的水自动分出一条路来。\n");
        this_player()->set_temp("likefish",1);
    } else
        tell_object(this_player(), 
             "你手握辟水珠，，但是不是用错地方了呢。\n" );
    return 1;

}
