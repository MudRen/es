#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "scale mail", "���ۼ�" );
	add( "id", ({ "scale", "mail" }) );
	set_short( "���ۼ�" );
	set_long("����һ������\��\����Ƭ���ۼס�\n");
	set( "unit", "��" );
	set( "type", "body" );
	set( "material", "heavy_metal" );
	set( "weight", 180 );
	set( "armor_class", 18 );
	set( "value", ({ 720, "silver" }) );
}
