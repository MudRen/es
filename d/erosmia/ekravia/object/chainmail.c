#include "../ekravia.h"
inherit ARMOR;

void	create()
{
	set_name("chainmail", "����");
	add( "id", ({ "mail","chainmail" }) );
	set_short( "����" );
	set_long(
		"һ�������Ƴɵġ��ס�\n"
	);
	set("unit","��");
	set( "type", "body" );
	set( "material", "light_metal" );
	set( "armor_class", 15 );
	set( "defense_bonus", 2 );
	set( "weight", 150 );
	set( "value", ({ 600, "silver" }) );
}






