// helm.c

#include "../moon.h"

inherit ARMOR;

void create()
{
    set_name("magic helmet", "月神盔");
    set_short("月神盔");
    add("id", ({ "helmet", "helm" }));
    set_long("由神力幻化而成的头盔。\n");
    set("unit", "顶");
    set("weight", 0);
    set("type", "head");
    set( "armor_class", 50 );
    set( "defense_bonus", 50 );
    set("special_defense",(["all":100])) ;
    set("no_sale", 1);
    set("prevent_drop", 1);
}

void unequip(int silent)
{
    tell_object(this_player(), "月神盔拒绝离开你的身体!\n");
}

int remove()
{
    object p;
    p = environment(this_object());

    if (p && query("equipped"))
        ::unequip(0);
    return ::remove();
}
