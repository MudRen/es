
#include "../../layuter.h"

inherit MONSTER ;

void create ()
{
        object boots,dagger,shield,legging,plate,cloak;

        ::create();
        set_level(10);
        set_name( "Rich man", "郑大户" );
        add ("id", ({ "draconian", "man","rich" }) );
        set_short(" 郑大户");
        set("unit","位");
        set("alignment",-100);
        set("weight",1000);
        set("wealth/gold",400);
        set_long(
           "郑大户是地下城中最有钱的人，他的口头禅是:老子什麽都没有就是钱多。\n"
        );
        set("natural_defense_bonus",30);
        set ("natural_weapon_class1", 60);
        set ("natural_min_damage1", 20);
        set ("natural_max_damage1", 30);
        set ("natural_armor_class", 70);
        set ("special_defense",(["all":60,"none":60]));
        set ("gender", "male");
       
        equip_armor(Lditem"boots");
        wield_weapon(Lditem"longsword2");
        set_perm_stat("str", 30);
        set_perm_stat("dex", 5);
        set_perm_stat("kar",30);
        set_c_limbs(({"身体","头部","脚部","手臂"}));
}       
