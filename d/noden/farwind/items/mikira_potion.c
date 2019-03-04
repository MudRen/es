#include <mudlib.h>

inherit POTION;

void create()
{
	potion::create();
	set_name( "mikira potion", "�׼���ҩˮ" );
	add( "id", ({ "potion", "mikira" }) );
	set_short( "�׼���ҩˮ" );
	set_long(
		"��ƿҩˮ�����ʾ��: ���׼��������Ա�ע��: ҽ�������á�\n"
	);
	set_healing( 20 );
	set( "no_sale", 1 );
	set( "unit", "ƿ" );
	set( "weight", 20 );
	set( "value", ({ 80, "silver" }) );
	set( "medication", 20 );
	set( "effect_critical", 100 );
}
