#include "../forest.h"

void create(object ob)
{
        if ( !ob ) return ;
        ob->set_level(5);
        ob->set_name( "elephant", "大象" );
        ob->set_short("大象");
        ob->set("unit","头");
        ob->set_long(@C_LONG
你看见一只巨大的动物，有著长长的鼻子、巨大的耳朵、与两根白色的长牙，
此时它正在森林中悠闲的漫步著。
C_LONG
        );
        ob->set_perm_stat("str", 8);
        ob->set_perm_stat("dex", 3);
        ob->set_natural_weapon(6,6,12);
        ob->set_natural_armor(25,0);
        ob->set_c_verbs(({"%s用它的长牙向%s攻击","%s用它的长鼻甩向%s"}));
        ob->set_c_limbs(({"鼻子","身体","耳朵","脚部","头部"}));
}
