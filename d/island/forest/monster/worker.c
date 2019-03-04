#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(7);
    set_name("Centaur Worker","��������");
    add("id",({"centaur","worker"}) );
    set_short("��������");
    set_long(@C_LONG
����һ��ħ��ġ���ū�����������ȱ��ȸ���ħ���һ֧��������ĵ��Ͽѻġ�����
���ϣ������������������������ǿ�������ֿ������˼���������ԣ��Ѿ��ĸ�����
�����ߣ������˵��ū�����Ҳ���û�����
C_LONG
       );
    set("gender","male");
    set("race","centaur");
    set("alignment",200);
    set("max_hp",120);
    set("hit_points",120);
    set_perm_stat("str",10);
    set_perm_stat("dex",10);
    set_natural_weapon(15,13,22);
    set_natural_armor(30,5);
    set("wealth/silver",200);
}
