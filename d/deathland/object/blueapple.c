#include "../echobomber.h"

inherit POTION;

void create()
{
	potion::create();
	set_name( "blue apple juice", "��ƻ��֭" );
	add( "id", ({ "juice" }) );
	set_short( " blue apple juice", "��ƻ��֭" );
	set_long(
		"The juice is blue,maybe you can drink it.\n",
		"һƿ��ƻ��֭,�������е���ĵ���Ӧ���ǿ��Ժȵġ�\n"
	);
	set_healing( 90 );
	set( "no_sale", 1 );
	set( "unit", "ƿ" );
	set( "weight", 30 );
	set( "value", ({ 750, "silver" }) );
	set( "medication", 30 );
	set( "effect_critical", 100 );
}
