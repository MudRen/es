#include "../oldcat.h"

inherit WEAPON;

void create()
{
       set_name("toy gun","���ǹ");
       add("id",({"gun",}) );
       set_short("���ǹ");
       set_long(
           "һ�����ǹ\n"
     	);
	
	set( "unit", "��" );
 	set( "weapon_class", 5 );
        set( "type","dagger");
	set( "min_damage", 5 );
	set( "max_damage", 10 );
	set( "weight", 50 );
	set( "value", ({ 15, "silver" }) );

}
