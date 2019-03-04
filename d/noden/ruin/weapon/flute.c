// flute.c

#include "../lilia.h"

inherit WEAPON;

void create()
{
    set_name("Silver flute", "��ɫ����");
    set_short("��ɫ����");
    add("id", ({"flute"}));
    set("unit", "��");
    set("weapon_class", 35);
    set("type", "blunt");
    set("min_damage", 10);
    set("max_damage", 25);
    set("weight", 100);
    set("value", ({1500, "silver"}));
    set("hit_func", "fireball");
}

int fireball(object victim, int damage)
{
    object p;

    if (!(p = environment(this_object())) || !living(p)) return 0;
    if (random(10) > 4) return 0;
    victim->receive_special_damage("fire", 5);
    victim->set("last_attacker", p);
    tell_object(p, set_color("\n�����ɫ���Ѵ����һ�Ż���ȼ�������ˣ�\n", "HIR"));
    tell_room(environment(p), set_color(p->query("c_name")+"����ɫ���Ѵ����һ�Ż���ȼ����"+victim->query("c_name"), "HIR"), p);

    return 1;
}

