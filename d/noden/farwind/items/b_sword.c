#include "../farwind.h"

inherit WEAPON;

void create()
{
	set_name("heavy broadsword", "����");
	add( "id", ({ "sword", "broadsword" }) );
	set_short("��������");
	set_long(
		"һ���ֳ������ض��ҷ��������������Զ����ı��������С�\n"
	);
	set( "unit", "��" );
	set( "weapon_class", 25 );
	set( "type", "longblade" );
	set( "min_damage", 13 );
	set( "max_damage", 28 );
	set( "bleeding", 10 );
	set( "weight", 160 );
	set( "nosecond", 1 );
	set( "value", ({ 66, "gold" }) );
}
