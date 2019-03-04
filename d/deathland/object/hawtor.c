#include <mudlib.h>

inherit POTION;

void create()
{
	potion::create();
	set_name( "hawtor chicken soup", "���Ӽ���" );
	add( "id", ({ "soup" }) );
	set_short( " hawtor chicken soup", "���Ӽ���" );
	set_long(
		"The chicken soup,maybe you can drink it.\n",
		"һ�޻��Ӽ���,������ʮ�����������¡������ƺ���һ�ֲ�ҩ\n"
	);
	set_healing( 100 );
	set( "no_sale", 1 );
	set( "unit", "��" );
	set( "weight", 30 );
	set( "value", ({ 750, "silver" }) );
	set( "medication", 40 );
	set( "effect_critical", 80 );
}
