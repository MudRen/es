#include "takeda.h"

inherit ARMOR;

void create()
{
        set_name("skeleton beads","人顶骨数珠");
        add("id",({"skeleton","beads"}) );
         set_short( "a skeleton beads","人顶骨数珠");
	set_long(
"This is a chain of beads make of skeleton . \n"
"由人顶骨做成的大数珠，共有十八粒，隐隐发出令人作呕的血腥气．\n"
);
	set( "unit", "个" );
	set( "weight", 100 );
	set( "type", "misc" );
	set( "material","stone");
        set( "defense_bonus", 7 );
	set( "no_sale",1);
	set( "value", ({ 250, "gold" }) );
        set( "special_defense",(["evil":-5 ,"divine":7]));
        set( "extra_stats",(["pie":-2]));
}
