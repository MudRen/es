#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(6);
    set_name("Daemon man","ħ��׳��");
    add("id",({"man","daemon"}) );
    set_short("ħ��׳��");
    set_long(@LONG
��׳����Ŀ��࣬������������ͷ�ྱ�������в���һ�ݣ��ѵ�ħ������Զ�
����������
LONG
            );
    set("unit","��");
    set("gender","male");
    set("race","daemon");
    set("alignment",-300);
    set_perm_stat("str",8);
    set("wealth/silver",150);
    set_natural_weapon(6,7,12);
    set_natural_armor(30,0);
    set("weight",700);
}
