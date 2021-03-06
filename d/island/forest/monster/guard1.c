#include "../tsunami.h"

inherit TMOB"army";

void create ()
{
        ::create();
        set_level(15);
        set_name( "Guard leader", "禁卫队长" );
        add ("id", ({ "guard","leader"}) );
        set_short( "魔族禁卫队长" );
        set_long(@C_LONG
此人乃是魔族中最强壮的战士，也是魔族的遥照天皇最为信赖的人之一，因此皇宫内
所有区域的安全都由他统筹负责。由於公主阿重霞的生日将至，所以天皇命令他特别
注意宫中所有人的一举一动，以防异族趁机入侵。
C_LONG
        );
        set("unit","位");
        set("race","daemon");
        set ("gender", "male");
        set("alignment",500);
        set("weight",700);
        set("wealth/gold",50);
        set_perm_stat("int",26);
        set_perm_stat("dex",13);
        set_perm_stat("str",13);
        set("tactic","melee");
        set("max_hp",300);
        set("hit_points",300);
        set_natural_armor(20,10);
        set_natural_weapon(35, 20, 30);
        set_skill("longblade",70);
        set_skill("parry",50);
        
        wield_weapon(TWEP"sword1");
        equip_armor(TOBJ"chainmail");
}