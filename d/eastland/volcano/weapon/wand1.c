#include "../oldcat.h"

inherit WEAPON;

void create()
{
	set_name("storm wand", "�����");
	add ("id",({ "wand",}) );
	set_short("�����");
	set_long(
        "����һ���ܺ������籩����ħ�ȣ�����Լ���Կ�����ͷ�����Ŀ�����Щ�Ŷ���\n"
	);
	
	set( "unit", "��" );
 	set( "weapon_class", 35 );
	set( "type", "wand" );
        set( "min_damage", 17 );
	set( "max_damage", 30 );
	set( "weight", 50 );
	set( "power_on", 1);
	set( "no_sale", 1);
	set( "value", ({ 5000, "silver" }) );

	set( "hit_func", "wand_hit" );
	set( "charge_left", 8 );
	set( "max_charge", 8 );
	set( "special_damage_type", "energy" );
	set( "special_damage", 80 );
	set( "special_c_msg", "����һ��籩��ʹ���еĵ��˽�����籩֮�С�\n" );
}