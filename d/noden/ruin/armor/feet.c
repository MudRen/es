// feet.c

#include "../lilia.h"

inherit ARMOR;

void create()
{
    set_name("magic feet", "��ħЬ");
    set_short("��ħЬ");
    add("id", ({ "feet" }));
    set_long("��ħ���û����ɵ�Ь�ӡ�\n");
    set("unit", "˫");
    set("weight", 0);
    set("type", "feet");
    set("material", "knight");
    set("armor_class", 8);
    set("defense_bonus", 3);
    set("no_sale", 1);
    set("prevent_drop", 1);
}

void unequip(int silent)
{
    tell_object(this_player(), "��ħЬ�ܾ��뿪�������!\n");
}

int remove()
{
    object p;
    p = environment(this_object());

    if (p && query("equipped"))
        ::unequip(0);
    return ::remove();
}
