
#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name( "evil katana", "妖刀" );
        set_short( "妖刀「村正」" );
        set_long(@C_LONG
这是一把长刃武士刀，雪亮的刀刃散发著妖异的红光，相传
这把刀已经成妖，喜欢吸收生物的血气，不管是友是敌。
C_LONG
        );
        set( "unit", "把" );
        set( "type", "longblade" );
        set( "weight", 90 );
        set( "weapon_class", 36 );
	set( "min_damage", 15 );
        set( "max_damage", 30 );
        set( "bleeding", 10 );
        set( "value", ({ 2700, "silver" }) );
}
