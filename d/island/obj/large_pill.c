#include <mudlib.h>

inherit PILL;

void create()
{
	pill::create();
#include <compress_obj.h>
	set_name( "large pill", "�󻹵�" );
	add( "id", ({ "pill" }) );
	set_short( "�󻹵�" );
	set_long(@C_LONG
����һ����ǧ���˲Ρ�ѩ����ҩ�����ƳɵĴ󻹵�������(eat)�����
�ָ�����������
C_LONG
	);
	set_healing( 100 );
	set( "no_sale", 1 );
        set( "weight", 30);
	set( "value", ({ 100, "gold" }) );
	set( "medication", 85 );
	set( "effect_critical", 50 );
}
