#include "takeda.h"


inherit WEAPON;

void create()
{
       set_name("scythe-lance","����ǹ");
       add("id",({"lance"}) );
       set_short("����ǹ");
	   set_long(
           "����һ���������ص�ǹ��ĩ������һ��С������\n"
	);
	
	set( "unit", "��" );
 	set( "weapon_class", 26 );
        set("type","thrusting");
	set( "min_damage", 21 );
	set( "max_damage", 28 );
	set( "weight", 130 );
	set( "value", ({ 42, "gold" }) );
        set( "nosecond",1);
}
	
