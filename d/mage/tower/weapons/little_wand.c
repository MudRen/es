#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name( "little wand", "Сħ��" );
	add( "id", ({ "wand" }) );
        set_short( "Сħ��" );
	set_long(@CLONG
    ����һ�Ѳ����۵�Сħ�ȣ����ֻ������������ˡ�
CLONG
	);
	set( "unit", "��" );
	set( "type", "wand" );
        set( "weapon_class", 5 );
        set( "min_damage", 3 );
        set( "max_damage", 6 );
        set( "weight", 40 );
        set( "value", ({ 10, "silver" }) );

	set( "hit_func", "wand_hit" );
        set( "charge_left", 5 );
        set( "max_charge", 5 );
        set( "power_on", 0);
        set( "special_damage_type", "divine" );
        set( "special_damage", 5 );
        set( "special_c_msg", "����ͷ����һ��΢���Ĺ�â��" );
}

