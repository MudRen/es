#include <mudlib.h>

inherit PILL;

void create()
{
	pill::create();
	set_name( "large herb pill", "�����֥" );
	add( "id", ({ "pill" }) );
	set_short( "�����֥" );
	set_long(
		"����һ��������֥�ľ���������(eat)����Իָ�����������\n"
	);
	set_healing( 50 );
	set( "no_sale", 1 );
	set( "weight", 20 );
	set( "value", ({ 8, "gold" }) );
	set( "unit", "��" );
	set( "medication", 40 );
	set( "effect_critical", 70 );
}
