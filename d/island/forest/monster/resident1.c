#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(7);
    set_name("Centaur Resident","������ס��");
    add("id",({"centaur","resident","inhabitant"}) );
    set_short("������ס��");
    set_long(@C_LONG
����һ��ħ��ġ�ũū�����������ȱ��ȸ���ħ���һ֧��������ĵ��Ͽѻġ�����
���ϣ������������������������ǿ�������ֿ������˼���������ԣ��Ѿ��ĸ��˺�
�����ߣ������˵��ū�����Ҳ���û������������¹��ˣ������ڹ�������Ϣ��
C_LONG
       );
    set("gender","male");
    set("race","centaur");
    set("alignment",-500);
    set("max_hp",120);
    set("hit_points",120);
    set_perm_stat("str",10);
    set_perm_stat("dex",10);
    set("wealth/silver",100);
    set_natural_weapon(15,13,22);
    set_natural_armor(30,5);
}

