#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(5);
    set_name("Daemon girl student","ħ��Ůѧ��");
    add("id",({"daemon","girl","student"}) );
    set_short("ħ��Ůѧ��");
    set_long(@LONG
һ��ħ���СŮ�����ƺ��������Ĵ��ڣ�ר�ĵ������������Ρ�
LONG
            );
    set("unit","��");
    set("alignment",-50);
    set("gender","female");
    set("race","daemon");
    set("weight",150);
    set_perm_stat("dex",6);
    set_natural_weapon(3,3,5);
    set_natural_armor(20,0);
    set("wealth/silver",20);
}    
