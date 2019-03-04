#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("thunder wand", "������");
	add ("id",({ "wand",}) );
	set_short("������");
	set_long(
        "����һ���ܺ��������ס���ħ�ȣ�����Լ���Կ�����ͷ������˿��⡣\n"
	);
	
	set( "unit", "��" );
 	set( "weapon_class", 39 );
	set( "type", "wand" );
	set( "min_damage", 20 );
	set( "max_damage", 30 );
	set( "weight", 50 );
	set( "power_on", 1);
	set( "no_sale", 1);
	set( "value", ({ 9000, "silver" }) );

	set( "hit_func", "wand_hit" );
	set( "charge_left", 8 );
	set( "max_charge", 8 );
	set( "special_damage_type", "electric" );
	set( "special_damage", 80 );
	set( "special_c_msg", "����һ��ǿ��ĵ��꣬����ڳ�������ȫ���飡" );
}
