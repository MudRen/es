#include "../echobomber.h"

inherit WEAPON;

void create()
{
       set_name("wooden stick","ľͷ����");
       add("id",({"stick",}) );
       set_short("ľͷ����");
       set_long(
           "��ľͷ���ɵĹ���\n"
     	);
	
	set( "unit", "��" );
 	set( "weapon_class", 7 );
    set("type","blunt");
	set( "min_damage", 2 );
	set( "max_damage", 8 );
	set( "weight", 50 );
	set( "value", ({ 18, "silver" }) );

}
