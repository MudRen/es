#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("evil plate","аħ����");
        add("id",({"plate","platemail"}) );
         set_short( "an evil plate","аħ����");
	set_long(
"This plate seems heavy and enhanced with evil power.\n"	
"����һ�����ص�����,�ƺ�����ħ����������\n"
	);
	set( "unit", "��" );
	set( "weight", 350 );
	set( "type", "body" );
	set( "material", "heavy_metal" );
	set( "armor_class", 30 );
	set( "defense_bonus", 0 );
	set( "value", ({ 380, "gold" }) );
    set( "special_defense",(["evil":15, "divine":-22 ]) );
}
