// Echo/item/troll corpse

#include "../echobomber.h"

inherit "/obj/corpse";

void create()
{
    object *stuff;
    ::create();
    ::set_name("troll","æﬁ»À");
    set("weight",1000);
    set("troll_corpse",1);
    set("load",1000);
}



