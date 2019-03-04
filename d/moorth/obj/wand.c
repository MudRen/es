#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "icewind wand", "�����" );
	add( "id", ({ "wand" }) );
	set_short( "�����" );
	set_long(
		"����һ����ɫ��ħ�ȣ����滹������˪״�������︽������ͷ��\n"
	);
	set( "unit", "��" );
	set( "type", "wand" );
	set( "weapon_class", 30 );
	set( "min_damage", 8 );
	set( "max_damage", 14 );
	set( "weight", 50 );
	set( "value", ({ 980, "silver" }) );

	set( "hit_func", "wand_hit" );
	set( "charge_left", 10 );
	set( "max_charge", 10 );
	set( "special_damage_type", "cold" );
	set( "special_damage", 50 );
	set( "special_c_msg", "����ͷ����һ����䣵ĺ��磬�㿴����Χ�Ŀ���������һ�ű�����" );
}
