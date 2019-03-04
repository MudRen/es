#include "mercury.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(10);
        set_name( "gray samurai", "������ʿ" );
        add ("id", ({ "samurai","gray"}) );
        set_short( "gray samurai","������ʿ");
        set("unit","λ");
        set_long(@AAA
������ʿ����ʿ���еȼ���͵���ʿ��ר�Ÿ���������Ѳ�ߵĹ���
AAA
        );
        set_perm_stat("str", 15);
        set_perm_stat("dex", 12);
        set_skill("longblade",50);
        set_skill("parry",45);
        set ("natural_weapon_class1", 12);
        set ("natural_min_damage1", 3);
        set ("natural_max_damage1", 8);
        set ("natural_armor_class", 30);
        set("natural_defense_bonus",6);
        set ("gender", "male");
        set("wealth/silver",60);
        set ("race", "human");
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
        
        wield_weapon(MOBJ"east_feather_blade.c");
        equip_armor(MOBJ"samurai_chainmail.c");
}
