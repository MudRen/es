#include "../moon.h"

inherit ARMOR;

void create()
{
    set_name("magic gauntlets", "月神手");
    set_short("月神手");
    add("id", ({ "gloves", "gauntlets" }));
    set_long("由神力幻化而成的手套。\n");
    set("unit", "双");
    set("weight", 0);
    set("type", "hands");
        set( "armor_class", 150 );
        set( "defense_bonus", 150 );
        set("special_defense",(["all":100])) ;
    set("no_sale", 1);
    set("prevent_drop", 1);
}

void unequip(int silent)
{
    tell_object(this_player(), "月神手拒绝离开你的身体!\n");
}

int remove()
{
    object p;
    p = environment(this_object());

    if (p && query("equipped"))
        ::unequip(0);
    return ::remove();
}
