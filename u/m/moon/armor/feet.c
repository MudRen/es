// feet.c

#include "../moon.h"

inherit ARMOR;

void create()
{
    set_name("magic feet", "����Ь");
    set_short("����Ь");
    add("id", ({ "feet" }));
    set_long("�������û����ɵ�Ь�ӡ�\n");
    set("unit", "˫");
    set("weight", 0);
    set("type", "feet");
        set( "armor_class", 150 );
        set( "defense_bonus", 150 );
        set("special_defense",(["all":100])) ;
    set("no_sale", 1);
    set("prevent_drop", 1);
}

void unequip(int silent)
{
    tell_object(this_player(), "����Ь�ܾ��뿪�������!\n");
}

int remove()
{
    object p;
    p = environment(this_object());

    if (p && query("equipped"))
        ::unequip(0);
    return ::remove();
}
