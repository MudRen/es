#include "../oldcat.h"

inherit WEAPON;

void create()
{
       set_name("wraith morningstar","�������ǡ�");
       add("id",({"morningstar","star"}) );
       set_short("�������ǡ�");
       set_long(
           "һ�Ѱ������ǡ�\n"
     	);
	
	set( "unit", "��" );
 	set( "weapon_class",27 );
        set( "type","chain");
	set( "min_damage", 13 );
	set( "max_damage", 30 );
	set( "weight", 100 );
	set( "value", ({ 300, "gold" }) );
}
