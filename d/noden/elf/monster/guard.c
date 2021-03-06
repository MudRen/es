
#include "../layuter.h"

inherit MONSTER ;

void create ()
{
        object boots,dagger,shield,legging,plate,cloak;

        ::create();
        set_level(10);
        set_name( "Elf guard", "精灵守卫" );
        add ("id", ({ "elf", "guard" }) );
        set_short( "精灵守卫" );
        set("unit","位");
        set_long(
           " 精灵守卫负责保护精灵村的安全，在精灵族的机要地方\n"
           "都有他的踪迹，他是位强力战士，请勿轻视他的存在。\n"
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
        set_c_verbs(({"%用%s向%s砍去","用%s向%s刺去"}));
        set_c_limbs(({"身体","头部","脚部","手臂"}));
        
        dagger= new(LWEAPON"guard_sword");
        dagger->move(this_object());
        wield_weapon(dagger);

        plate=new(LARMOR"mail");
        plate->move(this_object());
        equip_armor(plate);
}
