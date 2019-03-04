#include "../layuter.h"

inherit MONSTER;

void create()
{
        object knife;

        ::create();
        set_level(3);
        set_name( "little elf", "С����" );
        add ("id", ({"little elf", "elf" }) );
        set_short( "С����" );
        set_long(
           "  С�����Ǿ������ֵ������ߡ�\n"
        );
        set_perm_stat("str", 5);
        set_perm_stat("dex", 1);
        set ("natural_armor_class", 15);
        set ("gender", "male");
        set ("race", "elf");
        set("alignment",300);
        set("natural_max_damage1",10);
        set("natural_min_damage1",5);
        knife= new(LWEAPON"knife");
        knife->move(this_object());
        wield_weapon(knife);
        set("wealth/silver", 23);
        set_c_limbs(({"����","ͷ��","�ֱ�","�Ų�"}));
        set_c_verbs(({"��%s��%s��ȥ","��%s��%s��ȥ"}));
}
