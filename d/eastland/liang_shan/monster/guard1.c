
#include "../takeda.h"

inherit MONSTER ;

void create ()
{
        object boots,dagger,shield,legging,plate,cloak;

        ::create();
        set_level(12);
        set_name( "xxxx guard", "Ϻ��" );
        add ("id", ({ "xxxx", "guard" }) );
        set_short( "xxxx guard","Ϻ�� ");
        set("unit","λ");
        set_long("",
           " Ϻ�����𱣻������İ�ȫ���������ĸ������䶼�ɿ�������\n"
        );
        set_perm_stat("str", 16);
        set_perm_stat("dex", 16);
        set ("natural_weapon_class1", 18);
        set ("natural_min_damage1", 7);
        set ("natural_max_damage1", 10);
        set ("natural_armor_class", 45);
        set("natural_defense_bonus",9);
        set ("gender", "male");
        set("wealth/silver",50);
        set ("race", "monster");
        set_c_verbs(({"%��%s��%s��ȥ","��%s��%s��ȥ"}));
        set_c_limbs(({"����","ͷ��","�Ų�","����"}));
        wield_weapon(TWEAPON"guard_dagger");
        equip_armor(TARMOR"guard_mail1");
}
