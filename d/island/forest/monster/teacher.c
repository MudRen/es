#include "../tsunami.h"

inherit HOME+"magic";
inherit MONSTER;

void create()
{
    ::create();
    set_level(10);
    set_name("School Teacher","˽������");
    add("id",({"teacher"}) );
    set_short("˽������");
    set_long(@LONG
����һλ��ְ����������Ϊ�����������Ľ��Ρ�
LONG
            );
    set("unit","λ");
    set("race","daemon");
    set("weight",300);
    set("hit_points",300);
    set("max_hp",300);
    set_perm_stat("str",12);
    set_perm_stat("dex",13);
    set_skill("dodge",50);
    set("wealth/silver",200);
    set_natural_weapon(10,5,12);
    set_natural_armor(15,5);
    set("tactic_func","my_tactic");
    set("chat_chance",10);
    set("chat_output",({
 "�����߻���ͷ���૵�����֮�����Ա��ƣ��������Ϣ��Զ..................\n"}) );
}

int my_tactic(object victim)
{
    if( !(victim=query_attacker()) ) return 0;
    if( random(20)<3){
    tell_object(victim,@ALONG

˽����������ô�Ĺ������ҵ����ӷ��ƣ�������ɫ����.......
����������һ����̨������������!!!!!
ALONG
         );
    tell_room(environment(victim),
    "˽��������"+victim->query("c_name")+"�ƿڴ���漴������̨����!!\n"
    ,victim );
    victim->receive_special_damage("evil",20);
    report(this_object(),victim);
    return 1;
    }
}