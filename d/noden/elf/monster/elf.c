#include "../layuter.h"

inherit MONSTER;

void create()
{
        object boots,sword,cloak;

        ::create();
        set_level(5);
        set_name( "elf", "����" );
        add ("id", ({ "elf" }) );
        set_short( "����" );
        set("unit","λ");
        set_long(
           " ����λ�Ͱ����׵ľ��飬�������Ǵ������е�Ц��\n"
        );
        set("alignment",100);
        set("wealth/silver",10);
        set_perm_stat("str", 6);
        set_perm_stat("dex", 4);
        set ("natural_weapon_class1", 2);
        set ("natural_min_damage1", 1);
        set ("natural_max_damage1", 4);
        set ("natural_armor_class", 15);
        set ("gender", "male");
        set ("race", "elf");
        set_c_verbs(({"��%s��%s��ȥ","��%s��%s����","��%s��%s��ȥ"}));
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
       
        sword= new(LWEAPON"elf_sword");       
        sword->move(this_object());
        wield_weapon(sword);
        
        boots=new(LARMOR"wind_boots");
        boots->move(this_object());
        equip_armor(boots);

        cloak=new(LARMOR"wind_cloak");
        cloak->move(this_object());
        equip_armor(cloak);
}
