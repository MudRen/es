#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "steel braso mail", "���ؼ�" );
	add( "id", ({ "scale", "mail" }) );
	set_short( "an steel braso mail", "���ؼ�" );
	set_long(
		"You see a braso mail covered with many steel scales.\n",
		"����һ������\��\���Ƭ���ؼס�\n"
	);
	set( "unit", "��" );
	set( "type", "body" );
        set("material","heavy_metal");
	set( "weight", 180 );
	set( "armor_class", 20 );
	set( "value", ({ 350, "silver" }) );
}
