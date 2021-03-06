#include "../moon.h"

inherit ARMOR;

void create()
{
    set_name("magic arms", "月神臂");
    set_short("月神臂");
    add("id", ({ "arms", "armband" }));
    set_long("由神力幻化而成的臂环。\n");
    set("unit", "对");
    set("weight", 0);
    set("type", "arms");
        set( "armor_class", 150 );
        set( "defense_bonus", 150 );
        set("special_defense",(["all":100])) ;
    set("no_sale", 1);
    set("prevent_drop", 1);
}

void unequip(int silent)
{
    tell_object(this_player(), "月神臂拒绝离开你的身体!\n");
}

int remove()
{
    object p;
    p = environment(this_object());

    if (p && query("equipped"))
        ::unequip(0);
    return ::remove();
}
