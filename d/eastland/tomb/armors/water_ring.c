#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "water ring", "��ˮ��" );
	add( "id", ({ "ring" }) );
	set_short( "��ˮ��" );
	set_long( 
@C_LONG
ˮ֮���������Ľ�ָ��տ������ͬ��һ�����䡣
C_LONG
	);
	set( "unit", "ֻ" );
	set( "type", "finger" );
	set( "material", "element" );
	set( "defense_bonus", 4 );
	set( "special_defense", 
	     ([ "cold":5, "fire":-10 ]) );
	set( "extra_skills", ([ "inner-force":10 ]) );
	set( "extra_stats", ([ "dex":-1 ]) );      
	set( "weight", 5 );
	set( "value", ({ 1900, "silver" }) );
}
