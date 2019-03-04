#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(7);
    set_name("Farmer's wife","������ũ�������");
    add("id",({"centaur","farmer","wife"}) );
    set_short("������ũ�������");
    set_long(@C_LONG
����һ��ħ��ġ�ũū�����������ȱ��ȸ���ħ���һ֧��������ĵ��Ͽѻġ�����
���ϣ������������������������ǿ�������ֿ������˼���������ԣ��Ѿ��ĸ��˺�
�����ߣ������˵��ū�����Ҳ���û�����
C_LONG
       );
    set("gender","female");
    set("race","centaur");
    set("alignment",-500);
    set("max_hp",150);
    set("hit_points",150);
    set_perm_stat("str",8);
    set_perm_stat("dex",8);
    set_natural_weapon(13,10,20);
    set_natural_armor(25,0);
    set("wealth/silver",100);
    set("chat_chance",15);
    set("chat_output",({
    "������ũ�������һ�߹���һ�����:���Ϲ�����˵�����ǿô��������Ӧ\n"
    "��Ҫ��һ��ȥ�������Ҳ����.........\n"
      }) );
    set("inquiry",([
        "radish":"@@ask_radish"]) );
    wield_weapon(TWEP"hoe");
}

void ask_radish(object who)
{
  tell_object(who,"Ҫ�ܲ�ѽ��ȥ�Ǳ���(search)�����Ǳߺܶ�����\n");
  return ;
}