#include <mudlib.h>

inherit ARMOR;

void create()
{
	seteuid(getuid());
	set_name( "feather cloak", "��ë����" );
	add( "id", ({ "feather","cloak" }) );
   set_short( "��ë����" );
	set_long(
		"�����ë���ɵ����翴������....�³�������㴩�����ϽֵĻ���\n"
	);
	set( "unit", "��" );
	set( "type", "cloak" );
	set( "material", "leather" );
	set( "armor_class", 4 );
    set( "special_defense",([ "fire":-1 ]) );
	set( "weight", 70 );
	set( "value", ({ 20, "silver" }) );
}
