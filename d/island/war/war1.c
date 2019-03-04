#include "../island.h"

inherit IWAR"i_warvalue";

void create ()
{
        ::create();
        set_level(16);
        set_name( "black samurai", "������ʿ" );
        add ("id", ({ "samurai","black"}) );
        set_short("������ʿ");
        set("unit","λ");
        set_long(@ANGEL
������ʿ����ʿ�Ÿ����ر��߾�����ʿ���Ǹ������ؽ���Ϊ�������ʿ��Ҳ��ʮ������
�ĸ�
ANGEL
        );
        set("killer",1);
        set("justice",8);
        set_skill("longblade",70);
        set_skill("parry",60);
        set_skill("tactic",50);
        set("tactic","melee");
        set ("natural_weapon_class1", 30);
        set ("natural_min_damage1",10);
        set ("natural_max_damage1",35);
        set ("natural_armor_class", 50);
        set("natural_defense_bonus",8);
        set ("gender", "male");
        set("wealth/silver",350);
        set ("race", "human");
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
        
        wield_weapon(IWARO"steel_sword.c");
        equip_armor(IWARO"samurai_vest.c");
}