#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "buskins", "��ͳѥ" );
	set_short( "��ͳѥ" );
	set_long(
		"��˫��ͳѥ�������ĵײ����ʺϳ�;������˴�����\n"
	);
	set( "unit", "˫" );
	set( "type", "feet" );
	set( "material", "leather");
	set( "armor_class", 4 );
	set( "weight", 40 );
	set( "value", ({ 160, "silver" }) );
}
