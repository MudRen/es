#include "../nodania.h"

inherit WEAPON;

void create()
{
	seteuid(getuid());
	set_name("sabre", "�彣");
	add( "id", ({ "sword" }) );
	set_short("������彣");
	set_long(
		"������λ����������Я�����彣��\n"
	);
	set( "unit", "��" );
	set( "weight", 10 );
// Only wizards or monsters can wield this weapon.
	set( "weapon_class", 99 );
	set( "type", "longblade" );
	set( "min_damage", 9 );
	set( "max_damage", 99 );
	set( "value", ({ 300, "platinum" }) );
	set( "no_sale", 1 );
}
