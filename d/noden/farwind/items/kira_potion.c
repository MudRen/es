#include <mudlib.h>

inherit POTION;

void create()
{
	potion::create();
	set_name( "kira potion", "����ҩˮ" );
	add( "id", ({ "potion", "kira" }) );
	set_short( "����ҩˮ" );
	set_long(
		"��ƿҩˮ�����ʾ��: �����������Ա�ע��: ����drink��\n"
	);
	set_healing( 50 );
	set( "no_sale", 1 );
	set( "unit", "ƿ" );
	set( "weight", 25 );
	set( "value", ({ 250, "silver" }) );
    set( "medication", 40 );
    set( "effect_critical", 90 );
}
