#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("dark amulet","�ڰ������");
        add("id",({"amulet"}) );
         set_short( "a dark amulet","�ڰ������");
	set_long(
"����һ������а�� Yang ף�����Ļ����\n"
	);
	set( "no_sale",1);
	set( "unit", "��" );
	set( "weight", 10 );
	set( "type", "misc" );
	set( "material", "element" );
	set( "armor_class", 0 );
	set( "defense_bonus", 6 );
	set( "special_defense", ([ "evil":5, "divine":-10 ]) );
	set( "value", ({ 88, "gold" }) );
}
