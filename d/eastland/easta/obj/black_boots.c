#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black boots", "�ڲ�ѥ" );
	add( "id", ({ "boots" }) );
	set_short( "�ڲ�ѥ" );
	set_long("����һ˫�ú�ɫ����ĺ�׳�ѥ��\n");
	set( "unit", "˫" );
	set( "type", "feet" );
	set( "material", "cloth" );
	set( "weight", 30 );
	set( "armor_class", 4 );
	set( "value", ({ 310, "silver" }) );
}
