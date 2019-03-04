// helm.c

#include "../moon.h"

inherit ARMOR;

void create()
{
    set_name("magic helmet", "�����");
    set_short("�����");
    add("id", ({ "helmet", "helm" }));
    set_long("�������û����ɵ�ͷ����\n");
    set("unit", "��");
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
    tell_object(this_player(), "������ܾ��뿪�������!\n");
}

int remove()
{
    object p;
    p = environment(this_object());

    if (p && query("equipped"))
        ::unequip(0);
    return ::remove();
}
