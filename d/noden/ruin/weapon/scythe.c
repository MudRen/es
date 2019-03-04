// scythe.c

#include "../lilia.h"

inherit WEAPON;

void create()
{
    set_name("Death Scythe", "��������");
    add ("id",({ "scythe" }) );
    set_short("��������");
    set_long("һ�Ѻ�ʮ�ַ����Ĵ���������˵�������İ���������\n");
    set("unit", "��");
    set("weapon_class", 42);
    set("type", "longblade");
    set("min_damage", 25);
    set("max_damage", 45);
    set("weight", 150);
    set("no_sale", 1);
    set("nosecond", 1);
    set("value", ({ 10, "silver" }) );
}

