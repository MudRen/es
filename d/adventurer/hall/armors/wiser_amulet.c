#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "amulet", "�����" );
	add( "id", ({ "���߻����" }) );
	set_short( "a wiser amulet", "���߻����" );
	set_long(
		"This is Yamor's wiser amulet. You can see many symbols\n"
		"of fortune on it.\n",
		"��������һ������Ĭ�����������ߵģ����滭���˸���\n"
		"����ƽ�������˵����ġ�\n"
	);
	set( "type", "misc" );
	set( "material", "cloth");
	set( "armor_class", 0 );
	set( "defense_bonus", 6 );
    set( "special_defense", ([ "mental":5 ]) );
    set( "extra_status", ([ "int" : 1 ]) );
	set( "weight", 5 );
	set( "value", ({ 1000, "silver" }) );
}
