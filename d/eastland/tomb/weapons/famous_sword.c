#include "../almuhara.h"

inherit WEAPON;

void create()
{
    set_name("Famous Sword", "����" );
    add("id", ({"sword","famous sword"}) );
    set_short("���������衹");
	set_long(
           "һ�ѷǳ������ĳ������ڽ��ɴ���������С��  --- �����衹\n"
	);
	
	set( "unit", "��" );
 	set( "weapon_class", 33 );
        set( "type","longblade");
	set( "min_damage", 20 );
	set( "max_damage", 35 );
	set( "weight", 90 );
	set( "value", ({ 240, "gold" }) );
}

