#include "../island.h"

inherit IWAR"i_warvalue";

void create ()
{
        ::create();
        set_level(16);
        set_name( "blue samurai", "������ʿ" );
        add ("id", ({ "samurai","blue"}) );
        set_short("������ʿ");
        set("unit","λ");
        set_long(@ANGEL
������ʿ����ʿ�Ÿ����ر��߾�����ʿ
ANGEL
        );
        
        set_skill("axe",70);
        set_skill("parry",60);
        set_skill("tactic",50);
        set("tactic","melee");
        set("killer",1);
        set("justice",10);
        set ("natural_weapon_class1", 30);
        set ("natural_min_damage1",19);
        set ("natural_max_damage1",35);
        set ("natural_armor_class", 50);
        set("natural_defense_bonus",8);
        set ("gender", "male");
        set("wealth/silver",350);
        set ("race", "human");
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
        
        wield_weapon(IWARO"axe.c");
        equip_armor(IWARO"samurai_vest.c");
}