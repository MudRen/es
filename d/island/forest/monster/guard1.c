#include "../tsunami.h"

inherit TMOB"army";

void create ()
{
        ::create();
        set_level(15);
        set_name( "Guard leader", "�����ӳ�" );
        add ("id", ({ "guard","leader"}) );
        set_short( "ħ������ӳ�" );
        set_long(@C_LONG
��������ħ������ǿ׳��սʿ��Ҳ��ħ���ң�������Ϊ��������֮һ����˻ʹ���
��������İ�ȫ������ͳ�︺����춹�������ϼ�����ս�������������������ر�
ע�⹬�������˵�һ��һ�����Է�����û����֡�
C_LONG
        );
        set("unit","λ");
        set("race","daemon");
        set ("gender", "male");
        set("alignment",500);
        set("weight",700);
        set("wealth/gold",50);
        set_perm_stat("int",26);
        set_perm_stat("dex",13);
        set_perm_stat("str",13);
        set("tactic","melee");
        set("max_hp",300);
        set("hit_points",300);
        set_natural_armor(20,10);
        set_natural_weapon(35, 20, 30);
        set_skill("longblade",70);
        set_skill("parry",50);
        
        wield_weapon(TWEP"sword1");
        equip_armor(TOBJ"chainmail");
}