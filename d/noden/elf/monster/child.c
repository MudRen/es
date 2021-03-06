#include "../layuter.h"

inherit MONSTER;

void create()
{
        object knife;

        ::create();
        set_level(3);
        set_name( "little elf", "小精灵" );
        add ("id", ({"little elf", "elf" }) );
        set_short( "小精灵" );
        set_long(
           "  小精灵是精灵村快乐的制造者。\n"
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
        set_c_limbs(({"身体","头部","手臂","脚部"}));
        set_c_verbs(({"用%s向%s刺去","用%s向%s劈去"}));
}
