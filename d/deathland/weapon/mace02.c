#include "../echobomber.h"

inherit WEAPON;

void create()
{
        set_name("Mithril Mace","�����ﶤͷ�");
        add("id",({"mace",}) );
       set_short("�����ﶤͷ�");
       set_long(
         "һ�������ﶤͷ�.\n"
               );
	
	set( "unit", "��" );
 	set( "weapon_class", 24 );
       set("type","blunt");
	set( "min_damage", 15 );
	set( "max_damage", 30 );
	set( "weight", 180 );
	set( "value", ({ 170, "gold" }) );
}
