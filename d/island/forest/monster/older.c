#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(6);
    set_name("Daemon older","ħ������");
    add("id",({"older","daemon"}) );
    set_short("ħ������");
    set_long(@LONG
����������Ѿ�һ����ˣ�����������ʮ��Ӳ�ʵ����ӣ������ø����̶���һ��
������˼��ģ����
LONG
            );
    set("unit","��");
    set("gender","male");
    set("race","daemon");
    set("alignment",-250);
    set_perm_stat("str",9);
    set("wealth/silver",150);
    set_natural_weapon(6,7,12);
    set_natural_armor(35,0);
    set("weight",600);
    wield_weapon(TWEP"pipe");
}
