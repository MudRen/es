#include "mudlib.h"

void create(object ob)
{
        if ( !ob ) return ;
        ob->set_level(12);
        ob->set_name( "cheetah", "印度豹\ " );
        ob->set_short( "印度豹\ " );
        ob->set_long(@C_LONG
这是一只有著漂亮毛皮，修长身驱的动物。它的动作非常地快，
是一种具有危险性的肉食动物。
C_LONG
        );
        ob->set("unit","头");
        ob->set_perm_stat( "str", 18 );
        ob->set_perm_stat( "dex", 20 );
        ob->set_perm_stat( "int", 10 );
        ob->set_perm_stat( "kar", 18 );
        ob->set_skill( "dodge", 80);
        ob->set("max_hp", 350);
        ob->set("hit_points", 350);
        ob->set("special_defense", ([ "all":30, "none":15, "fire":3 ]) );
        ob->set("aim_difficulty",
            ([ "weakest":40, "ganglion":30 ]) );
        
        ob->set( "killer", 1);
        ob->set( "c_kill_msg", "突然间，印度豹\从树上向你猛扑了过来 !!!!!" );
        ob->set( "alignment", -400 );
        ob->set_natural_weapon(35,13,23);
        ob->set_natural_armor(63,30);

        ob->set_c_verbs( ({ "%s用它的利爪向%s抓去", "%s迅速地扑向%s" }) );
        ob->set_c_limbs( ({ "头部", "身体", "脚部"}) );
}
