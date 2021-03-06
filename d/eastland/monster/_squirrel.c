#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_level(1);
	ob->set_name( "squirrel", "松鼠" );
	ob->set_short( "松鼠" );
	ob->set_long(
		"你看到一只小松鼠在枝头间跑来跑去。\n"
	);
	ob->set( "unit", "只" );
	ob->set_perm_stat("kar", 3 );
	ob->set_perm_stat("dex", 4 );
	ob->set_c_verbs( ({ "%s用爪子往%s抓去" }) );
	ob->set_c_limbs( ({ "头部", "身体", "腿部", "尾巴" }) );
}
