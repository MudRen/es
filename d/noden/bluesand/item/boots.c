#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "long boots", "��ѥ" );
	add( "id", ({ "boots" }) );
   set_short( "��ѥ" );
	set_long( 
		"һ˫�ú���Ƥ���ɵĳ�ͳѥ��������Ʒ�ʲ���\n"
	);
	set( "unit", "˫" );
	set( "type", "feet" );
    set( "material", "leather");
	set( "armor_class", 6 );
	set( "special_defense",(["cold":3,]) );
	set( "value", ({ 320, "silver" }) );
	set( "weight", 50 );
}
