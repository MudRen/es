#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name( "mew", "海鸥" );
	add( "id", ({ "mew" }) );
	set_short( "海鸥" );
	set_long("这是一种海鸟\n");	
	set("unit","只");
    set( "alignment", -50 );
	set_perm_stat( "dex", 4 );
	set_c_verbs( ({ "%s往下俯冲，用嘴巴啄%s", "%s用爪子往%s抓下" }) );
	set_c_limbs( ({ "头部", "身体", "翅膀" }) );
#include <replace_mob.h>
}
