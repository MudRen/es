#include <mudlib.h>

inherit OBJECT;

void create()
{
        set_name("amaze root","奇异花的根");
        add( "id" , ({ "root" }) );
        set_short("奇异花的根");
        set_long("这是一段黑黑的、不起眼的树根。\n");
        set("unit","段");
        set("weight", 10);
        set("value", ({20, "silver"}) );
}
