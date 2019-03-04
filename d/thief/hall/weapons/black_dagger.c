//#pragma save_binary
#include <mudlib.h>

inherit WEAPON;

void create()
{
       set_name("black dagger","黑色匕首");
       add("id",({"dagger"}) );
       set_short("黑色匕首");
       set_long("这是一把黑色的匕首, 很适合在夜间使用。\n");
	set( "unit", "把" );
	set( "weight", 10 );
	set( "type","dagger");
	set( "min_damage",13);
	set( "max_damage",20);
	set( "weapon_class",16);
        set( "value", ({ 910, "silver"} ) );
	set( "extra_skills",(["backstab":2,]) );
}

