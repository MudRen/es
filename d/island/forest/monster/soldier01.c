#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(7);
    set_name("Daemon New Soldier","ħ���±�");
    add("id",({"soldier","daemon"}) );
    set_short("ħ���±�");
    set_long(@LONG
����ħ���±�ɵ�ʿ����
LONG
            );
    set("unit","��");
    set("gender","male");
    set("race","daemon");
    set("alignment",-100);
    set("hit_points",120);
    set("max_hp",120);
    set("wealth/silver",100); 
    set_natural_weapon(10,0,5);
    set_natural_armor(15,5);
    set_skill("parry",30);
    wield_weapon(TWEP"spear1");
}