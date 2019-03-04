
#include "../layuter.h"

inherit MONSTER ;

void create ()
{
        object weapon;

        ::create();
        set_level(3);
        set_name("Elven lady", "Ů����" );
        add ("id", ({"elf", "lady" }) );
        set_short( "Ů����" );
        set("unit","λ");
        set_long(
           " Ů���������ڵĹ����ߣ�������ǵ�Ŭ��ʹ�ľ����\n"
           " ����������������\n" 
        );
        set_perm_stat("str", 2);
        set_perm_stat("int", 4);
        set_perm_stat("kar", 4);
        set ("natural_weapon_class1", 1);
        set ("natural_min_damage1", 1);
        set("natural_max_damage1",2);
        set ("natural_armor_class", 15);
        set ("gender", "female");
        set("wealth/silver",30);
        set ("race", "elf");
        set_c_verbs(({"%��%s��%s��ȥ","��%s��%s��ȥ"}));
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
        
        weapon= new(LWEAPON"carver");
        weapon->move(this_object());
        wield_weapon(weapon);
}
