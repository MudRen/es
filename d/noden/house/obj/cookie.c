// /d/noden/house/obj/cock.c

#include <mudlib.h>

inherit OBJECT;

void create()
{
   set_name( "cookie", "小饼乾" );
   set_short("小饼乾");
	set_long(
             "这是一片小小的星形饼乾。\n"
	);
   set("unit", "片");
   set( "weight", 1 );
}
