#include "../echobomber.h"

inherit WEAPON;

void create()
{
       set_name("Silver steel Hammer","���־ޡ�");
       add("id",({"hammer",}) );
       set_short("���־ޡ�");
       set_long(
           "�����õ����־ޡ�\n"
     	);
	
	set( "unit", "��" );
 	set( "weapon_class", 33 );
    set("type","blunt");
    set("nosecond",1);
	set( "min_damage", 20 );
	set( "max_damage", 45 );
	set( "weight", 280 );
	set( "value", ({ 300, "gold" }) );

}
