#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "flamming wand", "������" );
	add( "id", ({ "wand" }) );
	set_short( "������" );
	set_long(
		"����һ�ѻ����ȣ������������͵�ħ���������о��Ļ�����������\n"
		"�����ǲ����ѡ��\n"
	);
	set( "unit", "��" );
	set( "type", "wand" );
	set( "weapon_class", 13 );
	set( "min_damage", 4 );
	set( "max_damage", 10 );
	set( "weight", 50 );
	set( "value", ({ 680, "silver" }) );

	set( "hit_func", "wand_hit" );
	set( "charge_left", 5 );
	set( "max_charge", 5 );
	set( "special_damage_type", "fire" );
	set( "special_damage", 30 );
	set( "special_c_msg", "����ͷð�����ܵĻ��棡" );
}

