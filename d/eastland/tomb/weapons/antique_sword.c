#include "../almuhara.h"

inherit WEAPON;

void create()
{
    set_name("Antique Sword", "�Ž�" );
    add("id", ({"sword"}) );
    set_short("�Ž������ɡ�");
	set_long(
           "һ�����͹��ⰻȻ�ĳ������ڽ��ɴ���������С��  --- �����ɡ�\n"
	);
	
	set( "unit", "��" );
 	set( "weapon_class", 32 );
        set( "type","longblade");
	set( "min_damage", 20 );
	set( "max_damage", 34 );
	set( "weight", 90 );
	set( "value", ({ 250, "gold" }) );
}

