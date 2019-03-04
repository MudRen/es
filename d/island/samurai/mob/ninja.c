#include "mercury.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(14);
        set_name( "Ninja", "����" );
        add ("id", ({"ninja"}) );
        set_short( "Ninja","����");
        set("unit","λ");
        set_long(@AAA
������ʿ�ŵ����ܲ��ӣ����߾��ŵ�һԱ�����Ǻ���ʿ��֮ͬ����������Ǹ���
�����ƻ����������������ɱ������ɱ����С�����ǵ�ս��ร�
AAA
        );
        set_skill("longblade",70);
        set_skill("parry",60);
        set_skill("dodge",60);
        set("hit_points",300);
        set("max_hp",300);
        set ("natural_weapon_class1", 30);
        set ("natural_min_damage1",10);
        set ("natural_max_damage1",25);
        set ("natural_armor_class", 64);
        set("natural_defense_bonus",10);
        set ("gender", "male");
        set("wealth/silver",320);
        set ("race", "human");
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
        
        wield_weapon(MOBJ"ninja_sword.c");
        equip_armor(MOBJ"ninja_cloth.c");
}
