#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("song amulet","�質֮��");
        add("id",({"amulet"}) );
         set_short( "a song amulet","�質֮��");
	set_long(
"���Ǹ��質�����,�ƺ����������и��������洫��\n"
	);
	set( "unit", "��" );
	set( "weight", 12 );
	set( "type", "misc" );
	set( "material", "element" );
	set( "armor_class", 0 );
	set( "defense_bonus", 8 );
	set( "special_defense", ([ "mental":6, "evil":3, "divine":-15 ]) );
	set( "value", ({ 150, "gold" }) );
}
