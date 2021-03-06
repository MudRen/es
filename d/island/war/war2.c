#include "../island.h"

inherit IWAR"i_warvalue";

void create ()
{
        ::create();
        set_level(16);
        set_name( "blue samurai", "蓝衣武士" );
        add ("id", ({ "samurai","blue"}) );
        set_short("蓝衣武士");
        set("unit","位");
        set_long(@ANGEL
蓝衣武士是武士团负责守备边境的武士
ANGEL
        );
        
        set_skill("axe",70);
        set_skill("parry",60);
        set_skill("tactic",50);
        set("tactic","melee");
        set("killer",1);
        set("justice",10);
        set ("natural_weapon_class1", 30);
        set ("natural_min_damage1",19);
        set ("natural_max_damage1",35);
        set ("natural_armor_class", 50);
        set("natural_defense_bonus",8);
        set ("gender", "male");
        set("wealth/silver",350);
        set ("race", "human");
        set_c_limbs(({"身体","头部","脚部","手臂"}));
        
        wield_weapon(IWARO"axe.c");
        equip_armor(IWARO"samurai_vest.c");
}