// bishop_robe.c

#include "../lilia.h"

inherit ARMOR;

void create()
{
    set_name("bishop robe", "��˾��");
    add("id", ({ "robe" }));
    set_short("��˾��");
    set_long("���Ǵ��˾���������ӣ������ý��������������֡�\n");
    set("unit", "��");
    set("weight", 80);
    set("type", "body");
    set("armor_class", 22);
    set("defense_bonus", 5);
    set("material", "healer");
    set("value", ({ 2000, "silver" }));
}

