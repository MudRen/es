#include "../echobomber.h"

inherit WEAPON;

void create()
{
	set_name("poet dagger","ʫ��ذ��");
       add("id",({"dagger",}) );
       set_short("ʫ��ذ��");
       set_long(
           "һ��ذ��,����������һֻ��\n"
     	);
	
	set( "unit", "��" );
 	set( "weapon_class", 14 );
    set("type","dagger");
	set( "min_damage", 7 );
	set( "max_damage", 16 );
	set( "weight", 25 );
	set( "value", ({ 450 , "silver" }) );

}
