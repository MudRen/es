#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "wind boots", "���ѥ" );
	add( "id", ({ "boots" }) );
	set_short( "���ѥ" );
	set_long( 
@C_TOPIC
���Ƿ�֮����������ѥ�ӣ���ҫ��ǳ��ɫ�Ĺ�â��
C_TOPIC
	);
	set( "unit", "˫" );
	set( "type", "feet" );
	set( "material", "cloth" );
	set( "armor_class", 6 );
	set( "defense_bonus", 2 );
	set( "extra_skills", ([ "dodge" :15 ]) );
	set( "extra_stats", ([ "pie":-1 ]) );     
	set( "weight", 25 );
	set( "value", ({ 1600, "silver" }) );
}
