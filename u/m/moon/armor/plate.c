// plate.c

#include "../moon.h"

inherit ARMOR;

void create()
{
    set_name("magic plate", "月神甲");
    set_short("月神甲");
    add("id", ({ "plate" }));
    set_long("由神力幻化而成的铠甲。\n");
    set("unit", "件");
    set("weight", 0);
    set("type", "body");
    set( "armor_class", 150 );
    set( "defense_bonus", 150 );
    set("special_defense",(["all":100])) ;
    set("no_sale", 1);
    set("prevent_drop", 1);
}

void unequip(int silent)
{
    tell_object(this_player(), "月神甲拒绝离开你的身体!\n");
}

int remove()
{
    object p;
    p = environment(this_object());

    if (p && query("equipped"))
        ::unequip(0);
    return ::remove();
}
