// leggings.c

#include "../lilia.h"

inherit ARMOR;

void create()
{
    set_name("magic shield", "��ħ��");
    set_short("��ħ��");
    add("id", ({ "shield" }));
    set_long("��ħ���û����ɵĶ��ơ�\n");
    set("unit", "��");
    set("weight", 0);
    set("type", "shield");
    set("material", "knight");
    set("armor_class", 8);
    set("defense_bonus", 6);
    set("no_sale", 1);
    set("prevent_drop", 1);
}

void unequip(int silent)
{
    tell_object(this_player(), "��ħ�ܾܾ��뿪�������!\n");
}

int remove()
{
    object p;
    p = environment(this_object());

    if (p && query("equipped"))
        ::unequip(0);
    return ::remove();
}
