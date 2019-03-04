// Echo/item/troll corpse'ear

#include "../echobomber.h"

inherit OBJECT;

void create()
{
    set_name("troll ear","¾ÞÈË¶ú¶ä");
    add("id",({"ear",}));
    set_short("a troll ear","¾ÞÈË¶ú¶ä");
    set_long("a troll ear.\n","¾ÞÈË¶ú¶ä.\n");
    set("weight",20);
    set("no_sale",1);
    set("value",({ 0,"copper"}) );
    set("receive_trollear",1);
}

