// hands.c

#include "../lilia.h"

inherit ARMOR;

void create()
{
    set_name("magic gauntlets", "��ħ��");
    set_short("��ħ��");
    add("id", ({ "gloves", "gauntlets" }));
    set_long("��ħ���û����ɵ����ס�\n");
    set("unit", "˫");
    set("weight", 0);
    set("type", "hands");
    set("material", "knight");
    set("armor_class", 4);
    set("defense_bonus", 4);
    set("no_sale", 1);
    set("prevent_drop", 1);
}

void unequip(int silent)
{
    tell_object(this_player(), "��ħ�־ܾ��뿪�������!\n");
}

int remove()
{
    object p;
    p = environment(this_object());

    if (p && query("equipped"))
        ::unequip(0);
    return ::remove();
}
