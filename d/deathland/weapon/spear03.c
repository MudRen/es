#include "../echobomber.h"

inherit WEAPON;

void create()
{
   // seteuid(getuid());
	set_name("silver long spear", "����ì");
	add ("id",({ "spear" }) );
	set_short("����ì");
	set_long(
            "һ�����Ƶĳ�ì\n"
	);
	set( "unit", "��" );
	set( "weapon_class", 23 );
	set( "type", "thrusting" );
	set( "min_damage", 9 );
	set( "max_damage", 28 );
	set( "weight", 180 );
	set( "value", ({ 980, "silver" }) );
}

