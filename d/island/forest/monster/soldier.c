#include "../tsunami.h"

inherit TMOB"army";

void create()
{
    ::create();
    set_level(8);
    set_name("Daemon Soldier","ħ��ʿ��");
    add("id",({"soldier","daemon"}) );
    set_short("ħ��ʿ��");
    set_long(@LONG
����ħ��ĵͽ�ʿ����
LONG
            );
    set("unit","��");
    set("gender","male");
    set("race","daemon");
    set("alignment",-200);
    set("hit_points",150);
    set("max_hp",150);
    set("wealth/silver",100); 
    set_natural_weapon(10,0,5);
    set_natural_armor(15,5);
    set_skill("parry",40);
    wield_weapon(TWEP"spear1");
}