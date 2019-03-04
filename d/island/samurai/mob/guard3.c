#include "mercury.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(14);
        set_name( "samurai guard", "��ʿ����" );
        add ("id", ({ "samurai","guard"}) );
        set_short( "samurai guard","��ʿ����");
        set("unit","λ");
        set_long(@AAA
����һ��ר�Ÿ�����ʿ�Ǳ���ǽ����ְ֮����ʿ���������ĵ���
�ƺ��ǳ�������
AAA
        );
        set_perm_stat("str",25);
        set_skill("dagger",70);
        set_skill("parry",60);
        set("hit_points",250);
        set("max_hp",250);
        set ("natural_weapon_class1", 27);
        set ("natural_min_damage1",7);
        set ("natural_max_damage1",18);
        set ("natural_armor_class", 40);
        set("natural_defense_bonus",8);
        set ("gender", "male");
        set("wealth/silver",300);
        set ("race", "human");
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
        
        wield_weapon(MOBJ"samurai_short_blade.c");
        equip_armor(MOBJ"samurai_chainmail.c");
}

void init()
{
tell_room(environment(this_object()),"ι��ι������Ϊ���ǹ۹�ʤ�����ٲ�����С���ұ���ร�\n");
}