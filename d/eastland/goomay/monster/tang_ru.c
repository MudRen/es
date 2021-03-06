
#include <../goomay.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(7);
	set_name("tang ru", "唐如");
	add( "id", ({ "ru","tang" }) );
	set_short("唐如");
	set_long(
"唐如是远从四川跑来古梅镇玩的小女孩， 她大概只有十五、六岁的样子，\n"+
"十分活泼可爱。她似乎很少出门，正一个人开开心心的四处东看西看...\n"  
	);
        set("race","human");
        set("gender","female");	
        set("wealth",(["silver":50])); 
        set( "unit", "位" );
	set( "alignment", 200 );
	set_natural_armor( 35, 14 );
	set_natural_weapon( 11, 8, 17 );
	set_perm_stat( "int", 10 );
	set_perm_stat( "pie", 2 );
	set_perm_stat( "dex", 9 );
	set_skill("dodge",35);
	set( "pursuing", 1 );
	set( "tactic_func", "emit_poison" );
	equip_armor(Obj"tang_ring");
} 

int emit_poison()
{
	object victim;

	if( random(25)>6 || !(victim= query_attacker()) ) return 0;
	tell_room( environment(this_object()), 
"唐如娇笑道 『让你瞧瞧四川唐门的厉害!!!』\n"
"纤手一扬，你的眼前突然爆出一团粉红色的烟雾, 你感到一阵晕眩。\n\n" 
 , 	 
	this_object() );
	(CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 7, 7 );
	return 1;
}
