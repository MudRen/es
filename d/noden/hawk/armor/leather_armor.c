#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "leather armor", "Ƥ��" );
	add( "id", ({ "armor" }) );
	set_short( "Ƥ��" );
	set_long(
		"���Ƥ������ˮţƤ���ɵģ�������������һ��Ƥ�������еĳ�ζ��\n"
	);
	set( "unit", "��" );
	set( "type", "body" );
	set( "material", "leather");
	set( "armor_class", 14 );
    set( "special_defense",
         ([ "cold":2, "fire":-4, "electric":1 ]) );
	set( "weight", 100 );
	set( "value", ({ 210, "silver" }) );
}
