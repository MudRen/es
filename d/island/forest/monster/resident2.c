#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(8);
    set_name("Centaur Hoodlum","��������å");
    add("id",({"centaur","hoodlum"}) );
    set_short("��������å");
    set_long(@C_LONG
����һ��ħ��ġ�ũū�����������ȱ��ȸ���ħ���һ֧��������ĵ��Ͽѻġ�����
���ϣ������������������������ǿ�������ֿ������˼���������ԣ��Ѿ��ĸ��˺�
�����ߣ������˵��ū�����Ҳ���û�����������һ�ó����������Ը�����å
���ˡ�
C_LONG
       );
    set("gender","male");
    set("race","centaur");
    set("alignment",-350);
    set("max_hp",120);
    set("hit_points",120);
    set_perm_stat("str",11);
    set_perm_stat("dex",11);
    set("killer",1);
    set("c_killer_msg","��å����������������ȣ���ɶ������������˹���....\n");
    set("wealth/silver",150);
    set_natural_weapon(15,23,26);
    set_natural_armor(32,5);
}

