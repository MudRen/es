#include <mudlib.h>

inherit PILL;

void create()
{
	pill::create();
#include <compress_obj.h>
	set_name( "green pill", "�ٲݵ�" );
	add( "id", ({ "pill" }) );
	set_short( "�ٲݵ�" );
	set_long(@C_LONG
����һ�����ϰ����̲�ҩ�����Ƴɵİٲݵ�������(eat)�����
�ָ�����������
C_LONG
	);
	set_healing( 30 );
	set( "no_sale", 1 );
        set( "weight", 10);
	set( "value", ({ 18, "gold" }) );
	set( "medication", 30 );
	set( "effect_critical", 65 );
}
