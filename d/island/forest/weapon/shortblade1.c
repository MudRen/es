#include "../tsunami.h"

inherit WEAPON;

void create()
{
    set_name("Light Sword","ħ�޽�");
    add("id",({"sword"}) );
    set_short("ħ�޽�");
    set_long(@LONG
����ħ�����û����ɵĹ⽣������ӵ�����âҫ�۵Ľ�����ʾ���Ѿ�����ֻħ��
������Լ�����Ὣ������������
LONG
            );
    set("unit","��");
    set("light",1);
    set("weapon_class",21);
    set("type","shortblade");
    set("min_damage",13);
    set("max_damage",26);
    set("weight",150);
    set("value",({650,"silver"}) );
}

