#include "../tsunami.h"

inherit TMOB"army";

void create()
{
    ::create();
    set_level(17);
    set_name("Police Mihosi","������ ����");
    add("id",({"police","mihosi"}) );
    set_short("������ ����");
    set_long(@LONG
������һλ����ˣ�����ʮ�������Ů�ӣ����������������޷����ܵ�ȱ�㣬
�Ǿ��ǳ���������Ϊ�ǣ�Ȼ�Ὺʼ��˼���룬�����Ϳ�ʼɵЦ��������ˣ�����Ȼ
�Ȱ�ά���ΰ��Ĺ����������أ�������Ͻ������ò�Ҫ�з����ľٶ���
LONG
            );
    set("unit","λ");
    set("gender","female");
    set("race","daemon");
    set("alignment",-1000);
    set("time_to_heal",5);

    set_natural_armor(50,30);
    set_natural_weapon(15,15,20);

    set_perm_stat("str",20);
    set_perm_stat("dex",25);
    set_perm_stat("int",35);
    set_perm_stat("kar",30);

    set("max_hp",500);
    set("hit_points",500);
    set_skill("dodge",50);
    set_skill("parry",80);
    set_skill("blunt",100);
    set("wealth/gold",200);
    set("special_defense",(["all":30,"none":20]) );
    set("aim_difficulty",([
    "critical":80,"vascular":40,"ganglion":30,"weakest":70]) );
    set("exp_reward",15000);

    set("moving",1);
    set("speed",30);
    set("patrol",({"east","west","north","south"}) );
    wield_weapon(TWEP"mace");
    equip_armor(TOBJ"headband1");
    equip_armor(TOBJ"feet1");
    equip_armor(TOBJ"cloth1");
}