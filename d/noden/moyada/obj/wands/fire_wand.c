#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "fire wand", "����" );
	add( "id", ({ "wand" }) );
	set_short( "����" );
	set_long(@CLONG
����һ�ѻ��ȣ������������͵�ħ���������о��Ļ�����������
�����ǲ����ѡ��
CLONG
        	);
	set( "unit", "��" );
	set( "type", "wand" );
	set( "weapon_class", 10 );
	set( "min_damage", 5 );
	set( "max_damage", 10 );
	set( "power_on", 1);
	set( "weight", 40 );
	set( "value", ({ 500, "silver" }) );

	set( "hit_func", "wand_hit" );
	set( "charge_left", 10 );
	set( "max_charge", 10 );
	set( "special_damage_type", "fire" );
	set( "special_damage", 15 );
	set( "special_c_msg", "����ͷ���һ�Ż���" );
}
