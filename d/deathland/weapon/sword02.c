#include "../echobomber.h"

inherit WEAPON;

void create()
{
        set_name("Longsword of Molader","Ī���³���");
        add("id",({"sword","longsword",}) );
        set_short("Ī���³���");
      	set_long(
           "һ��Ī���»���ר�õķ�������\n"
	);
	
	set( "unit", "��" );
 	set( "weapon_class", 30 );
    set("type","longblade");
	set( "min_damage", 15 );
	set( "max_damage", 30 );
	set( "weight", 100 );
	set( "value", ({ 220, "gold" }) );

}
