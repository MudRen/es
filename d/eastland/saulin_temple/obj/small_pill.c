#include <mudlib.h>

inherit PILL;

void create()
{
	pill::create();
	set_name( "herb pill", "С����֥" );
	add( "id", ({ "pill" }) );
	set_short( "С����֥" );
	set_long(
		"����һ�������֥�ľ���������(eat)����Իָ�һЩ������\n"
	);
	set_healing( 20 );
	set( "no_sale", 1 );
	set( "weight", 10 );
	set( "value", ({ 5, "gold" }) );
	set( "unit", "��" );
	set( "medication", 20 );
	set( "effect_critical", 80 );
}
