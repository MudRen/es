#include "../nodania.h"

inherit WEAPON;

void create()
{
	seteuid(getuid());
	set_name("sword", "�һ���");
	add( "id", ({ "sword" }) );
	set_short("�һ���");
	set_long(
	"���ǰ���ϯ���ض���������Я���Ľ��������������������ˮ������\n"
	);
	set( "unit", "��" );
	set( "weight", 10 );
// Only wizards or monsters can wield this weapon.
	set( "weapon_class", 33 );
	set( "type", "longblade" );
	set( "min_damage", 16 );
	set( "max_damage", 44 );
	set( "value", ({ 300, "platinum" }) );
	set( "no_sale", 1 );
}
