#include "../tsunami.h"

inherit TMOB"army";

void create()
{
    ::create();
    set_level(11);
    set_name("Daemon Warrior","ħ��սʿ");
    add("id",({"warrior","daemon"}) );
    set_short("ħ��սʿ");
    set_long(@LONG
����ħ���һ��սʿ��
LONG
            );
    set("unit","��");
    set("gender","male");
    set("race","daemon");
    set("alignment",-500);
    set("hit_points",250);
    set("max_hp",250);
    set_natural_weapon(30,13,23);
    set_natural_armor(30,10);
    set("wealth/silver",250);
    set_skill("parry",60);
    set_skill("block",60);
    wield_weapon(TWEP"spear1");
    equip_armor(TOBJ"shield3");
}
