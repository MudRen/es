#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "hell wand", "ڤԨ��" );
	add( "id", ({ "wand" }) );
	set_short( "ڤԨ��" );
	set_long(
"����һ�Ѻ�ɫ���Ͼɵ�ħ�ȣ��ȱ�����ϡ����һ��ҹ���ͷ��\n"
	);
	set( "unit", "��" );
	set( "type", "wand" );
	set( "weapon_class", 30 );
	set( "min_damage", 8 );
	set( "max_damage", 15 );
	set( "weight", 55 );
	set( "value", ({ 1000, "silver" }) );

	set( "hit_func", "wand_hit" );
	set( "charge_left", 10 );
	set( "max_charge", 10 );
	set( "special_damage_type", "cold" );
	set( "special_damage", 45+random(10));
	set( "special_c_msg",
 "����ͷӿ��һ�ɿẮ�����磬�㿴�����絽�ĵط�������ˣ�" );
}

