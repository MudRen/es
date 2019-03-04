#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("statue", "MIYUKIµñÏñ");
        add( "id", ({ "statue" }) );
        set_short( "MIYUKIµñÏñ" );
        set_long(
                 "ÕâÊÇ°¬ÈûË¹Ì«Ì«MiyukiµÄµñÏñ¡£\n"
        );
        set( "unit", "×ù");
        set( "weight", 50 );
        set( "value", ({ 0, "silver" }) );
        set("get_my_statue",1);
}
