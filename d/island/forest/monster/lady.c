#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(5);
    set_name("Daemon lady","ħ�帾Ů");
    add("id",({"lady","woman","daemon"}) );
    set_short("ħ�帾Ů");
    set_long(@LONG
�⸾Ů�ڲ����������ص����У�ͬʱҲ���ͻ����͵Ĺ����ߡ�
LONG
            );
    set("unit","��");
    set("gender","female");
    set("race","daemon");
    set("alignment",-200);
    set_perm_stat("str",8);
    set("wealth/silver",150);
    set_natural_weapon(5,5,8);
    set_natural_armor(30,0);
    set("weight",400);
    wield_weapon(TWEP"mop");
}
