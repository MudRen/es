#include "../tsunami.h"

inherit ARMOR;

void create()
{
    set_name("Wind Chainmail","ħ��֮��");
    add("id",({ "chainmail","mail"}) );
    set_short("ħ��֮��");
    set_long(@LONG
����ħ�����ù�ħ������������ľ�������.
LONG
            );
    set("unit","��");
    set("type","body");
    set("material","element");
    set("armor_class",25);
    set("defense_bonus",2);
    set("special_defense",(["fire":20,"cold":20]) );
    set("weight",250);
    set("value",({300,"gold"}) );
}
