#include "../echobomber.h"

inherit WEAPON;

void create()
{
        set_name("break sword of Wind","��֮�Ͻ�");
        add("id",({"sword"}) );
       set_short("��֮�Ͻ�");
       set_long(
         "һ�Ѷϵ�����,��˵�����������������˵�����\n"
               );
	
	set("no_sale",1);
	set( "unit", "��" );
 	set( "weapon_class", 23 );
 	set("second",1);
    set("type","shortblade");
	set( "min_damage", 16 );
	set( "max_damage", 25 );
	set( "weight", 71 );
	set( "value", ({ 1800, "silver" }) );
}
