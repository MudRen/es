#include "../tsunami.h"

inherit WEAPON;

void create()
{
    set_name("Wood blade","ľ��");
    add("id",({"blade"}) );
    set_short("ľ��");
    set_long(@LONG
���ǰ�һ��ϰ���õ�ľ��!
LONG
             );
    set("unit","��");
    set("type","longblade");
    set("weapon_class",10);
    set("min_damage",5);
    set("max_damage",10);
    set("weight",10);
    set("value",({100,"silver"}) );
}