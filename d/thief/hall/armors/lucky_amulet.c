#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "lucky amulet", "���˻����" );
	add( "id", ({ "���˻����", "amulet" }) );
	set_short( "���˻����" );
	set_long(
		"���Ǹ��ƽ����Ļ��������������˸���\n"
		"����ƽ�������˵����ġ�\n"
	);
	set( "type", "misc" );
	set( "material", "cloth");
	set( "armor_class", 0 );
	set( "defense_bonus", 6 );
    set( "special_defense", ([ "mental":5 ]) );
	set( "extra_stats",([ "kar" : 2 ]) );
	set( "weight", 5 );
	set( "value", ({ 1000, "silver" }) );
}
