#include "../forest.h"

void create(object ob)
{
        if ( !ob ) return ;
        ob->set_level(8);
        ob->set_name( "gorilla", "人猿" );
        ob->set_short("人猿");
        ob->set("unit","只");
        ob->set_long(@C_LONG
在你面前的是一只人型的动物，有健全的双手双脚，但是全身毛茸茸的。
它似乎较其他的动物聪明一些，灵慧的模样令人不舍得杀它。
C_LONG
        );
        ob->set_perm_stat( "str", 12 );
        ob->set_perm_stat( "dex", 18 );
        ob->set_perm_stat( "int", 18 );
        ob->set_perm_stat( "kar", 15);
        ob->set("wimpy",50);
        ob->set_skill("dodge",100);
        ob->set("max_hp", 300);
        ob->set("hit_points", 300);
        ob->set("special_defense", ([ "all":40, "none":20, ]) );
        ob->set("aim_difficulty",
        	([ "critical":45, "vascular":80, "weakest":30, "ganglion":60 ]) );
        
        ob->set( "alignment",500 );
        ob->set_natural_weapon(17,12,20);
        ob->set_natural_armor(50,30);
        ob->set_c_verbs(({"%s用它的拳头向%s攻击","%s用它的脚向%s踢去",
                      "%s用它的头向%s猛烈地撞去"}));
        ob->set_c_limbs(({"身体","脚部","头部","手部"}));
}
