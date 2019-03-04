#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "holyword wand", "ʥ����" );
	add( "id", ({ "wand" }) );
	set_short( "ʥ����" );
	set_long(
		"����һ����ڵķ��ȣ����滹�̻�����\�����صķ��š�\n"
	);
	set( "unit", "��" );
	set( "type", "wand" );
	set( "weapon_class", 35 );
	set( "min_damage", 8 );
	set( "max_damage", 14 );
	set( "weight", 70 );
	set( "value", ({ 2000, "silver" }) );
	set( "hit_func", "wand_hit" );
	set( "charge_left", 10 );
	set( "max_charge", 10 );
	set( "special_damage_type", "divine" );
	set( "special_damage", 40 );
	set( "special_c_msg", "����ͷ����һ����ɫ�Ĺ�â !!\n"+
	    "�㿴���������ԡ�����ڿ��з��� !!\n" );
}

