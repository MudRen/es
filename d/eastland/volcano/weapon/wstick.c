#include "../oldcat.h"

inherit WEAPON;

void create()
{
       set_name("heavy stick","����");
       add("id",({"stick",}) );
       set_short("����");
       set_long(
           "һ�����صĹ���\n"
     	);
	
	set( "unit", "��" );
 	set( "weapon_class", 10 );
        set( "type","blunt");
	set( "min_damage", 5 );
	set( "max_damage", 15 );
	set( "weight", 80 );
	set( "value", ({ 20, "silver" }) );

}
