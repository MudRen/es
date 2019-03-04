#include "mercury.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(16);
        set_name( "guard samurai", "守卫武士" );
        add ("id", ({ "samurai","guard"}) );
        set_short( "guard samurai","守卫武士");
        set("unit","位");
        set_long(@ANGEL
这是个专门负责千川楼安全的武士，也是武士团中最强的武士，你如果想
在千川楼做坏事的话，最好别被他看见！
ANGEL
        );
        
        set_skill("longblade",85);
        set_skill("parry",85);
        set_skill("tactic",70);
        set("tactic","assault");
        set ("natural_weapon_class1", 30);
        set ("natural_min_damage1",10);
        set ("natural_max_damage1",25);
        set ("natural_armor_class", 45);
        set("natural_defense_bonus",8);
        set ("gender", "male");
        set("wealth/silver",400);
        set ("race", "human");
        set_c_limbs(({"身体","头部","脚部","手臂"}));
        
        wield_weapon(MOBJ"lakonia_sword.c");
        equip_armor(MOBJ"samurai_vest.c");
        equip_armor(MOBJ"samurai_gloves.c");
        equip_armor(MOBJ"samurai_helm.c");
}