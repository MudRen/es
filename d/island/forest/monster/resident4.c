#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(6);
    set_name("Centaur Badgirl","����������Ů");
    add("id",({"centaur","badgirl","girl"}) );
    set_short("����������Ů");
    set_long(@C_LONG
����һ��ħ��ġ�ũū�����������ȱ��ȸ���ħ���һ֧��������ĵ��Ͽѻġ�����
���ϣ������������������������ǿ�������ֿ������˼���������ԣ��Ѿ��ĸ��˺�
�����ߣ������˵��ū�����Ҳ���û�������Ů����Ϊ��ͻ�С�����������£�
���Ĵ�������
C_LONG
       );
    set("gender","female");
    set("race","centaur");
    set("alignment",-100);
    set("max_hp",100);
    set("hit_points",100);
    set("killer",1);
    set("c_killer_msg","������Ů�������ɶ��������һ�ƴ��˹���......\n");
    set_perm_stat("str",8);
    set_perm_stat("dex",8);
    set("wealth/silver",20);
    set_natural_weapon(10,8,15);
    set_natural_armor(25,0);
}

