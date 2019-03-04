
#include "../layuter.h"

inherit MONSTER ;

void create ()
{
        object boots,dagger,shield,legging,plate,cloak;

        ::create();
        set_level(10);
        set_name( "Elf guard", "��������" );
        add ("id", ({ "elf", "guard" }) );
        set_short( "��������" );
        set("unit","λ");
        set_long(
           " �����������𱣻������İ�ȫ���ھ�����Ļ�Ҫ�ط�\n"
           "���������ټ�������λǿ��սʿ�������������Ĵ��ڡ�\n"
        );
        set_perm_stat("str", 15);
        set_perm_stat("dex", 14);
        set ("natural_weapon_class1", 15);
        set ("natural_min_damage1", 3);
        set ("natural_max_damage1", 6);
        set ("natural_armor_class", 40);
        set("natural_defense_bonus",6);
        set ("gender", "male");
        set("wealth/silver",50);
        set ("race", "elf");
        set_c_verbs(({"%��%s��%s��ȥ","��%s��%s��ȥ"}));
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
        
        dagger= new(LWEAPON"guard_sword");
        dagger->move(this_object());
        wield_weapon(dagger);

        plate=new(LARMOR"mail");
        plate->move(this_object());
        equip_armor(plate);
}
