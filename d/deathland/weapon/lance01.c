#include "../echobomber.h"

inherit WEAPON;

void create()
{
    seteuid(getuid());
	set_name("Lance of Molader", "Ī���³�ǹ");
	add ("id",({ "lance" }) );
	set_short("Ī���³�ǹ");
	set_long(
            "һ��ĩ��Ī���»��ҵ�����ר�õĳ�ǹ\n"
	);
	set( "unit", "��" );
	set( "weapon_class", 25 );
	set( "type", "thrusting" );
	set( "min_damage", 10 );
	set( "max_damage", 36 );
	set( "weight", 190 );
	set( "value", ({ 2150, "silver" }) );
}

