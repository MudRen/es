
#include <mudlib.h>
void create(object ob)
{
        if (!ob) return ;
        seteuid(getuid()) ;
	ob->set_level(1);
	ob->set_name( "stone frog", "石头蛙" );
	ob->add( "id", ({ "frog" }) );
	ob->set_short( "石头蛙" );
	ob->set_long(
	 "你看到一只灰褐色的青蛙，身上有著石头般纹路的皮肤，正不断地
传来「咯咯」的低沈叫声。\n"
	);
	ob->set( "unit", "只" );
	ob->set( "alignment", 500 );
	ob->set( "unbleeding", 1 );
	ob->set_perm_stat("str", 5);
	ob->set_c_verbs( ({ "%s用後腿往%s一踢" }) );
	ob->set_c_limbs( ({ "头部", "身体", "腿部" }) );
}
