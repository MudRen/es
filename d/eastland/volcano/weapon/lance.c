#include "../oldcat.h"

inherit WEAPON;

void create()
{
       set_name("bodyguard lance","����ǹ");
       add("id",({"lance"}) );
       set_short("����ǹ");
       set_long(
           "һ�����Ϻý�������ĳ�ǹ\n"
     	);
	
	set( "unit", "��" );
 	set( "weapon_class", 25 );
        set( "type","jousting");
	set( "min_damage", 10 );
	set( "max_damage", 23 );
	set( "weight", 150 );
	set( "value", ({ 80, "gold" }) );
}
