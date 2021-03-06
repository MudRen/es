
#include "../takeda.h"

inherit MONSTER ;

void create ()
{
        object boots,dagger,shield,legging,plate,cloak;

        ::create();
        set_level(12);
        set_name( "xxxx guard", "虾兵" );
        add ("id", ({ "xxxx", "guard" }) );
        set_short( "xxxx guard","虾兵 ");
        set("unit","位");
        set_long("",
           " 虾兵负责保护龙宫的安全，在龙宫的各个角落都可看到他。\n"
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
        set_c_verbs(({"%用%s向%s砍去","用%s向%s刺去"}));
        set_c_limbs(({"身体","头部","脚部","腰部"}));
        wield_weapon(TWEAPON"guard_dagger");
        equip_armor(TARMOR"guard_mail1");
}
