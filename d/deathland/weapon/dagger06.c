#include "../echobomber.h"

inherit WEAPON;

void create()
{
       set_name("curved knife","������С��");
       add("id",({"knife",}) );
       set_short("������С��");
       set_long(
     	 "һ��������С��.\n"
     	);
	
	set( "unit", "��" );
 	set( "weapon_class", 7 );
    set("type","dagger");
	set( "min_damage", 4 );
	set( "max_damage", 7 );
	set( "weight", 32 );
	set( "value", ({ 70 , "silver" }) );

}
