#include "mercury.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(16);
        set_name( "guard samurai", "������ʿ" );
        add ("id", ({ "samurai","guard"}) );
        set_short( "guard samurai","������ʿ");
        set("unit","λ");
        set_long(@ANGEL
���Ǹ�ר�Ÿ���ǧ��¥��ȫ����ʿ��Ҳ����ʿ������ǿ����ʿ���������
��ǧ��¥�����µĻ�����ñ���������
ANGEL
        );
        
        set_skill("longblade",85);
        set_skill("parry",85);
        set_skill("tactic",70);
        set("tactic","assault");
        set ("natural_weapon_class1", 30);
        set ("natural_min_damage1",10);
        set ("natural_max_damage1",25);
        set ("natural_armor_class", 45);
        set("natural_defense_bonus",8);
        set ("gender", "male");
        set("wealth/silver",400);
        set ("race", "human");
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
        
        wield_weapon(MOBJ"lakonia_sword.c");
        equip_armor(MOBJ"samurai_vest.c");
        equip_armor(MOBJ"samurai_gloves.c");
        equip_armor(MOBJ"samurai_helm.c");
}