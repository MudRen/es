#include "takeda.h"

inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("green-dragon glaive ","青龙偃月刀");
       add("id",({"glaive","green-dragon",}) );
       set_short("青龙偃月刀");
	   set_long(@C_LONG
这是武圣关公所用的青龙偃月刀，破坏力相当大，但没有过人的力量
是拿不动的
C_LONG	);
	
	set( "unit", "把" );
 	set( "weapon_class", 48 );
        set("type","longblade");
	set( "min_damage", 30 );
	set( "max_damage", 53 );
	set( "weight", 250 );
	set( "nosecond", 1 );
        set( "bleeding",10);
	set( "value", ({ 1010, "gold" }) );
}

