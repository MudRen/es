#include "../tsunami.h"

inherit WEAPON;

void create()
{
    set_name("Wind Dagger","����ذ��");
    add("id",({ "dagger" }) );
    set_short("����ذ��");
    set_long( @C_LONG
����һ�Ѿ�����Ƶ�ذ�ף������ĵ��з�����������⣬�ݷ��ڿ�����Ҫ��ʳ��Ѫ��
C_LONG
            );
    set("unit","��");
    set("weapon_class",25);
    set("type","dagger");
    set("min_damage",15);
    set("max_damage",22);
    set("weight",50);
    set("value", ({400,"silver"}) );
}
