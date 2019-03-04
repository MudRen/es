#include "../echobomber.h"

inherit WEAPON;

void create()
{
	set_name("fire wand", "�ػ�֮��");
	add ("id",({ "wand",}) );
	set_short("�ػ�֮��");
	set_long(
        "����һ���ܺ��������򡹵�ħ�ȣ�����Լ���Կ�����ͷ������˿��⡣\n"
	);
	
	set( "unit", "��" );
 	set( "weapon_class", 25 );
	set( "type", "wand" );
	set( "min_damage", 10 );
	set( "max_damage", 18 );
	set( "weight", 60 );
	set( "value", ({ 200, "gold" }) );

	set( "hit_func", "wand_hit" );
	set( "charge_left", 15 );
	set( "max_charge", 15 );
	set( "special_damage_type", "fire" );
	set( "special_damage", 15 );
//	set( "special_msg", " launches a fireball, you are almost stunned!\n" );
	set( "special_c_msg", "����һ�Ż���,������������ȼ��\n" );
}
