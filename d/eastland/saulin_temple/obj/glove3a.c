#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "white bracers", "����ʯ����" );
	add( "id", ({ "bracers" }) );
	set_short( "����ʯ����" );
	set_long(
		"����һ����ĳ�ֲ�֪���İ�ʯͷ������ֻ����������൱�ء�\n"
	);
	set( "unit", "˫" );
	set( "type", "hands" );
	set( "armor_class", 5 );
        set("material","stone");
	set( "weight", 70 );
	set( "value", ({ 1000, "silver" }) );
}
