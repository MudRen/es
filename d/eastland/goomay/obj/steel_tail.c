#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "highsteel tail armor", "����β��" );
	add( "id", ({ "tail","armor" }) );
	set_short( "a high \steel tail armor ", "����β��" );
	set_long(
		"You see a steel tail armor .\n",
		"����һ�״��ִ����β�ף��и߶ȵķ�������\n"
	);
	set( "unit", "��" );
	set( "type", "tail" );
        set("material","heavy_metal");
	set( "weight", 100 );
	set("armor_class",7);
	set( "value", ({ 450, "silver" }) );
}
