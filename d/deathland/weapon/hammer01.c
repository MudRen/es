#include "../echobomber.h"

inherit WEAPON;

void create()
{
       set_name("Mithril Hammer","�ޡ�");
       add("id",({"hammer",}) );
       set_short("������ޡ�");
       set_long(
           "�����õ�������ޡ�\n"
     	);
	
	set( "unit", "��" );
 	set( "weapon_class", 25 );
    set("type","blunt");
	set( "min_damage", 15 );
	set( "max_damage", 30 );
	set( "weight", 230 );
	set( "value", ({ 100, "gold" }) );

}
