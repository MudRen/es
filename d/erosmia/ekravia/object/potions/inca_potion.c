#include <mudlib.h>

inherit POTION;

void create()
{
	potion::create();
	set_name( "inca potion", "ӡ��ҩˮ" );
	add( "id", ({ "potion", "inca" }) );
	set_short( "ӡ��ҩˮ" );
	set_long( @LONG
�����ɰ�����ά�Ǹ����ز���һ������, ��һЩ������ҩ�ľ�ħ�������
�ɵ�ҩˮ, ���������ҽ��������
LONG
	);
	set_healing( 20 );
	set( "no_sale", 1 );
	set( "unit", "ƿ" );
	set( "weight", 20 );
	set( "value", ({ 100, "silver" }) );
	set( "medication", 20 );
	set( "effect_critical", 100 );
}
