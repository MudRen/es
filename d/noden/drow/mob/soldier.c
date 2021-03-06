#include "../iigima.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(10);
        set_name( "Drow soldier","黑暗精灵士兵" );
        add ("id", ({ "drow", "soldier" }) );
        set_short( "Drow soldier","黑暗精灵士兵" );
        set("unit","位");
        set_long(
@C_LONG
这是黑暗精灵村的士兵，也是黑暗精灵们防御外侮的力量。但是最近
因为有祭祀的大典，他们都移防到禁断之地，防止意外发生。　　　　　　
他正面无表情的站著。
C_LONG
        );
        set_perm_stat("str", 15);
        set_perm_stat("dex", 14);
        set ("natural_weapon_class1", 18);
        set ("natural_min_damage1", 8);
        set ("natural_max_damage1", 18);
        set ("natural_armor_class", 42);
   set( "special_defense", ([
      "all":15,"fire":-10,"cold":-10,"evil":30,"divine":-30,"none":5 ]) );
        set ("gender", "male");
        set("wealth/copper",500);
   set("weight", 500);
        set ("race", "drow");
        set_c_verbs(({"%用%s向%s砍去","用%s向%s刺去"}));
        set_c_limbs(({"身体","头部","手臂"}));
        wield_weapon(OBJ"copper_sword");
        equip_armor(ARM"shield");
        equip_armor("/d/eastland/easta/obj/brass_helm");
        equip_armor(ARM"copper_arm");
}

