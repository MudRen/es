#include "../echobomber.h"

inherit WEAPON;

void create()
{
       set_name("Mithril Axe","�޸�");
       add("id",({"axe",}) );
       set_short("������޸�");
       set_long(
           "�����õ�������޸�\n"
     	);
	
	set( "unit", "��" );
 	set( "weapon_class", 22 );
    	set("type","axe");
    	set("bleeding",10);
	set( "min_damage", 10 );
	set( "max_damage", 22 );
	set( "weight", 180 );
	set( "value", ({ 330, "gold" }) );

}
