#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "sleet wand", "������" );
	add( "id", ({ "wand" }) );
	set_short( "������" );
	set_long(
		"����һ�ѱ����ȣ�������ħ���������о��Ļ����������\n"
		"�����ǲ����ѡ��\n"
	);
	set( "unit", "��" );
	set( "type", "wand" );
	set( "weapon_class", 23 );
	set( "min_damage", 14 );
	set( "max_damage", 22 );
	set( "power_on", 1);
	set( "weight", 40 );
	set( "value", ({ 1500, "silver" }) );

	set( "hit_func", "wand_hit" );
	set( "charge_left", 10 );
	set( "max_charge", 10 );
	set( "special_damage_type", "cold" );
	set( "special_damage", 35 );
	set( "special_c_msg", "����ͷ���һ�ű�����" );
}
