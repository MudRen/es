#include <mudlib.h>

inherit POTION;

void create()
{
	potion::create();
#include <compress_obj.h>
	set_name( "makira potion", "�꼪��ҩˮ" );
	add( "id", ({ "potion", "makira" }) );
	set_short( "�꼪��ҩˮ" );
	set_long(
		"��ƿҩˮ�����ʾ��: ���꼪�������Ա�ע��: ����ҽ���á�\n"
	);
	set_healing( 90 );
	set( "no_sale", 1 );
	set( "unit", "ƿ" );
	set( "weight", 30 );
	set( "value", ({ 500, "silver" }) );
	set( "medication", 70 );
	set( "effect_critical", 80 );
}
