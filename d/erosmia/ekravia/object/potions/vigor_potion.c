#include <mudlib.h>

inherit POTION;

void create()
{
	potion::create();
	set_name( "vigor potion", "����ҩˮ" );
	add( "id", ({ "potion", "vigor" }) );
	set_short( "����ҩˮ" );
	set_long( @LONG
����һƿ͸����ɫ��ҩˮ, ҩƿƿ�׵ı�ǩ����д��:
�������ƣ��������? ������ƿ�����ҩˮ����ʹ���������������ָ̻�
  ����!��
LONG
	);
	set_healing( 5 );
	set( "no_sale", 1 );
	set( "unit", "ƿ" );
	set( "weight", 15 );
	set( "value", ({ 500, "silver" }) );
	set( "medication", -90 );
	set( "effect_critical", 0 );
}
