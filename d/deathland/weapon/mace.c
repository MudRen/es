#include "../echobomber.h"

inherit WEAPON;

void create()
{
        set_name("Black Mace","��ɫ��ͷ��");
        add("id",({"mace",}) );
       set_short("��ɫ��ͷ��");
       set_long(
         "���������������Ƴɵĺ�ɫ��ͷ��.\n"
               );
	
	set( "unit", "��" );
 	set( "weapon_class", 30 );
    set("type","blunt");
	set( "min_damage", 19 );
	set( "max_damage", 36 );
	set( "weight", 180 );
	set( "value", ({ 400, "gold" }) );
}
