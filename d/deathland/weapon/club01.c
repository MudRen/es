#include "../echobomber.h"

inherit WEAPON;

void create()
{
       set_name("stone club","ʯ�ƹ���");
       add("id",({"club",}) );
       set_short("ʯ�ƹ���");
       set_long(
           "�����õ�ʯ�ƹ���\n"
     	);
	
	set( "unit", "��" );
 	set( "weapon_class", 15 );
    set("type","blunt");
	set( "min_damage", 5 );
	set( "max_damage", 25 );
	set( "weight", 200 );
	set( "value", ({ 1, "gold" }) );

}
