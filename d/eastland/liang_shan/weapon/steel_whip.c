#include "takeda.h"

inherit WEAPON;

void create()
{
       set_name("steel whip","水磨八□钢鞭");
       add("id",({"whip","steel_whip",}) );
       set_short("水磨八□钢鞭");
	   set_long(
           "这是一把用特殊金属制成的钢鞭，因为太过坚硬而不能铸造，只好用\n"
	   "水沙慢慢打磨．鞭身是八角形构造，□特别突出，被打到可能很痛．\n"
	
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 40 );
        set("type","whip");
	set( "min_damage", 25 );
	set( "max_damage", 35 );
	set( "weight", 150 );
	set( "value", ({ 410, "gold" }) );
        set_c_verbs(({
    "%s鞭梢挥出一股劲风，打向%s",
    "%s随手一挥，打中%s",
    "%s由空中如电般挥向%s",}));
    set("extra_skills",(["anatomlogy": 10 ]));
}

