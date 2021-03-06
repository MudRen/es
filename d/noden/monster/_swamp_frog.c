#include <mudlib.h>

void create(object ob)
{
    if ( !ob ) return ;
	ob->set_level(6);
	ob->set_name( "swamp frog", "沼泽蛙" );
	ob->add( "id", ({ "frog" }) );
   ob->set_short( "沼泽蛙" );
	ob->set_long(
		"一只又大又黏的绿色沼泽蛙正一动也不动地趴在沼泽的烂泥里。\n"
	);
	ob->set( "unit", "只" );
	ob->set( "alignment", 500 );
	ob->set_skill( "anatomlogy", 30 );
	ob->set_temp( "aiming_loc", "ganglion" );
	ob->set_c_limbs( ({ "後腿", "头部", "身体" }) );
	ob->set_c_verbs( ({ "%s张嘴往%s一咬", "%s用它的舌头往%s一舔" }) );
	ob->set_natural_armor( 10, 15 );
	ob->set_natural_weapon( 10, 8, 11 );
}
