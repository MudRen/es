#include "../echobomber.h"

inherit WEAPON;

void create()
{
        set_name("holy shortsword","��ʥ�̽�");
        add("id",({"sword","shortsword"}) );
       set_short("��ʥ�̽�");
       set_long(
         "һ����ʥ�Ķ̽�,��˵������ʥ����ʹ�õ�������� .\n"
               );
	
	set("no_sale",1);
	set( "unit", "��" );
 	set( "weapon_class", 35 );
 	set("second",1);
    set("type","shortblade");
	set( "min_damage", 22 );
	set( "max_damage", 33 );
        set( "weight",95 );
	set( "value", ({ 3000, "silver" }) );
}
