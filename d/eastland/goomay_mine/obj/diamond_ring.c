#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "diamond ring", "��ʯ��ָ" );
	add( "id", ({ "ring","diamond"}) );
	set_short( "diamond ring", "��ʯ��ָ" );
	set_long(@C_LONG
һֻ������âҫ�۵���ʯ��ָ���������ܹ�����ӣ�
C_LONG
	);
	set( "unit", "ֻ" );
	set( "type", "finger" );
        set( "material", "element");
	set( "defense_bonus", 5 );
	set( "special_defense", 
	     ([ "magic":5 ]) );      
	set( "weight", 5 );
	set( "value", ({ 6000, "silver" }) );
}
