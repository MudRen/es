#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(6);
    set_name("Centaur Woman","������ũ��");
    add("id",({"centaur","woman"}) );
    set_short("������ũ��");
    set_long(@C_LONG
����һ��ħ��ġ�ũū�����������ȱ��ȸ���ħ���һ֧��������ĵ��Ͽѻġ�����
���ϣ������������������������ǿ�������ֿ������˼���������ԣ��Ѿ��ĸ��˺�
�����ߣ������˵��ū�����Ҳ���û������������¹��ˣ������ڹ�������Ϣ��
C_LONG
       );
    set("gender","female");
    set("race","centaur");
    set("alignment",-300);
    set("max_hp",120);
    set("hit_points",120);
    set_perm_stat("str",8);
    set_perm_stat("dex",8);
    set("wealth/silver",50);
    set_natural_weapon(10,8,15);
    set_natural_armor(25,0);
}

