#include <mudlib.h>

inherit POTION;

void create()
{
	potion::create();
	set_name( "green potion", "����ҩˮ" );
	add( "id", ({ "potion", "green" }) );
	set_short( "����ҩˮ" );
	set_long( @LONG
���ǰ�����ά��������������ʦ������������ҩ, ӵ�о��ѵ�����Ч����
LONG
	);
	set_healing( 95 );
	set( "no_sale", 1 );
	set( "unit", "ƿ" );
	set( "weight", 15 );
	set( "value", ({ 750, "silver" }) );
	set( "medication", 70 );
	set( "effect_critical", 80 );
}
