#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("dark bishop amulet","�ڰ����̻����");
        add("id",({"amulet"}) );
         set_short( "a dark bishop amulet","�ڰ����̻����");
	set_long(
"����һ������а�� Yang ף�����Ļ����\n"
	);
	set( "no_sale",1);
	set( "unit", "��" );
	set( "weight", 10 );
	set( "type", "misc" );
	set( "material", "element" );
	set( "armor_class", 0 );
	set( "defense_bonus", 8 );
	set( "special_defense", ([ "evil":7, "divine":-15 ]) );
	set( "value", ({ 188, "gold" }) );
}
