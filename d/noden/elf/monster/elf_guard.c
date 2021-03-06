#include "../layuter.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(14);
        set_name( "Elf guard", "精灵守卫" );
        add ("id", ({ "elf", "guard" }) );
        set_short( "精灵守卫" );
        set("unit","位");
        set_long(
          "这个精灵守卫负责保护大草原的和平，他是位超强力战士，请勿等闲视之。\n"
        );
        set("max_hp", 1000);
        set("hit_points", 1000);
        set_perm_stat("str", 28);
        set_perm_stat("dex", 28);
        set_perm_stat("int", 19);
        set_perm_stat("pie", 19);
        set_perm_stat("kar", 25);
        set_natural_weapon( 42, 20, 40 );
        set_natural_armor( 80, 40 );
        set("gender", "male");
        set("wealth/gold",35);
        set("race", "elf");
        set_c_limbs(({"身体","头部","脚部","手臂"}));
        
        wield_weapon(LWEAPON"guard_sword");
        equip_armor(LARMOR"mail");
}
