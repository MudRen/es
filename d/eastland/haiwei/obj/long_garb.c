#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "long garb", "�������" );
	add( "id", ({ "garb" }) );
	set_short( "�������" );
	set_long("����һ������ͨ�ĳ�����ӡ�\n");
	set( "unit", "��" );
	set( "type", "body" );
	set( "material", "cloth" );
	set( "armor_class", 8 );
	set( "defense_bonus", 1 );
	set( "weight", 50 );
	set( "value", ({ 240, "silver" }) );
}
