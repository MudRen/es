#include "../echobomber.h"

inherit WEAPON;

void create()
{
   // seteuid(getuid());
	set_name("standard spear", "��׼��ì");
	add ("id",({ "spear" }) );
	set_short("��׼��ì");
	set_long(
            "һ�ѱ�׼�ĳ�ì\n"
	);
	set( "unit", "��" );
	set( "weapon_class", 15 );
	set( "type", "thrusting" );
	set( "min_damage", 7 );
	set( "max_damage", 20 );
	set( "weight", 170 );
	set( "value", ({ 550, "silver" }) );
}

