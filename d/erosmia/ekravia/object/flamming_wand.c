#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "flamming wand", "�����" );
	add( "id", ({ "wand" }) );
	set_short( "�����" );
	set_long(@CLONG
    ����һ�ѻ���ȣ������������͵�ħ���������о��Ļ�����������
�����ǲ����ѡ��
CLONG
	);
	set( "unit", "��" );
	set( "type", "wand" );
	set( "weapon_class", 13 );
	set( "min_damage", 7 );
	set( "max_damage", 14 );
	set( "weight", 50 );
	set( "value", ({ 680, "silver" }) );

	set( "hit_func", "wand_hit" );
	set( "charge_left", 6 );
	set( "max_charge", 6 );
	set( "power_on", 1);
	set( "special_damage_type", "fire" );
	set( "special_damage", 30 );
	set( "special_c_msg", "����ͷð�����ܵĻ����" );
}

