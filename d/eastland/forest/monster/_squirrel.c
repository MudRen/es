#include "../forest.h"

void create(object ob)
{
		if ( ! ob ) return ;
        ob->set_level(2);
        ob->set_name( "squirrel", "松鼠" );
        ob->set_short( "松鼠" );
        ob->set_long(
                "你看到一只有著长长尾巴，灵活大眼睛的小动物在枝头间跑来跑去。\n"
        );
        ob->set( "unit", "只" );
        ob->set_perm_stat("kar", 3 );
        ob->set_perm_stat("dex", 5 );
        ob->set_natural_weapon(4,2,3);
        ob->set_natural_armor(7,0);
        ob->set_c_verbs( ({ "%s用爪子往%s抓去" }) );
        ob->set_c_limbs( ({ "头部", "身体", "腿部", "尾巴" }) );
}
