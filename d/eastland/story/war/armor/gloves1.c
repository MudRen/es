#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("wind gloves","风神套");
        add("id",({"gloves"}) );
        set_short("风神套");
	set_long(@C_LONG
一件上绣云朵的纯白色手套，类似用蚕丝编织而成的。
C_LONG	         );
	set( "unit", "件" );
	set( "weight",40 );
	set( "type", "hands" );
        set("material","cloth");
	set( "armor_class", 3 );
	set( "defense_bonus", 2 );
	set( "value", ({ 2000, "silver" }) );
}
