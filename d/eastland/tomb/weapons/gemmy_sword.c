#include "../almuhara.h"

inherit WEAPON;

void create()
{
    set_name("Gemmy Sword", "����" );
    add("id", ({"sword","gemmy sword"}) );
    set_short("������������");
	set_long(
           "һ�ѱ�����õĳ������ڽ��ɴ���������С��  --- ��������\n"
	);
	
	set( "unit", "��" );
 	set( "weapon_class", 34 );
        set( "type","longblade");
	set( "min_damage", 20 );
	set( "max_damage", 33 );
	set( "weight", 90 );
	set( "value", ({ 280, "gold" }) );
}

