#include "../echobomber.h"

inherit WEAPON;

void create()
{
    set_name("Black shortsword", "��ɫ�̽�");
    add("id",({"sword","shortsword"}) );
    set_short("��ɫ�̽�");
    set_long(
         "���ǰ���С�����õ���߶̽�.\n"
    );
	
	set( "unit", "��" );
 	set( "weapon_class", 7 );
    set( "type","shortblade");
	set( "min_damage", 3 );
	set( "max_damage", 8 );
	set( "weight", 50 );
	set( "value", ({ 100, "silver" }) );
}
