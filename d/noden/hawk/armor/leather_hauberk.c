#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "leather hauberk", "��Ƥ��" );
	add( "id", ({ "hauberk" }) );
	set_short( "��Ƥ��" );
	set_long(
		"������ص�Ƥ������ҰţƤ���ɵģ�������������һ��Ƥ�������еĳ�ζ��\n"
	);
	set( "unit", "��" );
	set( "type", "body" );
	set( "material", "leather");
	set( "armor_class", 20 );
    set( "special_defense",
               ([ "cold":2, "electric":-3, "acid":2 ]) );
	set( "weight", 200 );
	set( "value", ({ 510, "silver" }) );
}
