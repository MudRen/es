#include <mudlib.h>

inherit PILL;

void create()
{
	pill::create();
#include <compress_obj.h>
	set_name( "small pill", "С����" );
	add( "id", ({ "pill" }) );
	set_short( "С����" );
	set_long(@C_LONG
����һ�����˲Ρ���֥��ҩ�����Ƴɵ�С����������(eat)�����
�ָ�һЩ������
C_LONG
	);
	set_healing( 60 );
	set( "no_sale", 1 );
        set( "weight", 20);
	set( "value", ({ 45, "gold" }) );
	set( "medication", 50 );
	set( "effect_critical", 60 );
}
