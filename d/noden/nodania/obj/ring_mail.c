#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "ring mail", "����" );
	add( "id", ({ "mail", "ring" }) );
	set_short( "����" );
	set_long(
		"����һ�����ף��ó�ǧ������������Ӻ϶��ɡ�\n"
	);
	set( "unit", "��" );
	set( "type", "body" );
	set( "material", "light_metal" );
	set( "armor_class", 10 );
	set( "weight", 110 );
	set( "value", ({ 140, "silver" }) );
}
