#include "../moon.h"

inherit ARMOR;

void create()
{
    set_name("magic arms", "�����");
    set_short("�����");
    add("id", ({ "arms", "armband" }));
    set_long("�������û����ɵıۻ���\n");
    set("unit", "��");
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
    tell_object(this_player(), "����۾ܾ��뿪�������!\n");
}

int remove()
{
    object p;
    p = environment(this_object());

    if (p && query("equipped"))
        ::unequip(0);
    return ::remove();
}
