#include <mudlib.h>

inherit PILL;

void create()
{
	pill::create();
	set_name( "puty seed", "����������" );
	add( "id", ({ "seed" }) );
	set_short( "����������" );
	set_long(@C_LONG
����һ��ǧ�������ӣ����������¾������ܷ���ף����, 
���������Իָ�����������
C_LONG
	);
	set_healing( 120 );
	set( "no_sale", 1 );
	set( "weight", 8 );
	set( "value", ({ 10, "gold" }) );
}
