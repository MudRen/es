#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(3);
    set_name("Daemon student","ħ��ѧ��");
    add("id",({"daemon","student"}) );
    set_short("ħ��ѧ��");
    set_long(@LONG
һ��ħ���С�к����������ڿ�������������ע���ʱ���ī֭˦�������ϣ�
LONG
            );
    set("unit","��");
    set("alignment",-50);
    set("gender","male");
    set("race","daemon");
    set("weight",200);
    set_perm_stat("str",5);
    set_natural_weapon(2,2,5);
    set_natural_armor(15,0);
    set("wealth/silver",10);
}    
