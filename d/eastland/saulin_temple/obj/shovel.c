#include "../saulin_temple.h"

inherit WEAPON;

void create()
{
	set_name("Shovel", "�����");
	add ("id",({ "shovel" }) );
	set_short("�����");
	set_long(@C_LONG
һ�Ѳ��ӣ��Ƿ��������������ġ��������Ĳ�Եʮ�ֵķ��������㲻��
�����������ǹ��߻���������
C_LONG
	);
	set( "weapon_class", 20 );
	set( "type", "blunt" );
	set( "min_damage", 12 );
	set( "max_damage", 20 );
	set( "weight", 50 );
	set( "no_sale", 1);
	set( "value", ({ 50, "gold" }) );
	set( "unit", "��" );
}
