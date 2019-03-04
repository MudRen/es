#include <mudlib.h>

inherit WEAPON;
void create()
{
	set_name("heavy iron sword","玄铁重剑");
	add ("id",({ "sword"}) );
        set_short("玄铁重剑");
	set_long(@C_LONG
这是一把通体拗黑的重型兵器。玄铁重剑的剑身并不怎麽锋利，雕工也不怎麽精细
，黑沈沈的不怎麽顺手，看起来宛如是块黑色大石。当年，剑客「八神吹雪」凭著
这一把玄铁重剑打遍江湖无敌手，他手底下工夫直是叫人匪疑所思。
C_LONG
	);
	set( "unit", "把" );
        setup_weapon("longblade", 35,20,30);
	set( "weight", 100 );
	set( "value", ({ 5000, "silver" }) );
}

