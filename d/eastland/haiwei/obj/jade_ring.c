#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "jade ring", "����ָ" );
	add( "id", ({ "ring" }) );
	set_short( "����ָ" );
	set_long("����һ����Ư��������ָ��\n");
	set( "type", "finger" );
	set( "material", "element" );
	set( "defense_bonus", 2 );
	set( "special_defense", ([ "divine" :2 ]) );
	set( "weight", 5 );
	set( "value", ({ 310, "silver" }) );
}
