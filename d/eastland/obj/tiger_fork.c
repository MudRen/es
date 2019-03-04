#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "tiger fork", "虎叉" );
	add( "id", ({ "fork" }) );
   set_short( "虎叉" );
	set_long(
		"这是一把又长又重的虎叉，三个钢尖在光线下亮晃晃地杀气腾腾。\n"
	);
	set( "unit", "把" );
	set( "weight", 190 );
	setup_weapon( "thrusting", 23, 9, 27 );
	set( "nosecond", 1 );
        set( "bleeding", 10 );
	set( "value", ({ 89, "gold" }) );
}
