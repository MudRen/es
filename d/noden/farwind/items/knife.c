#include <mudlib.h>

inherit WEAPON;

void create()
{
	if ( clonep(this_object()) )
	set_default_ob(base_name(this_object()));
else {
	set_name( "knife", "С��" );
	set_short( "С��" );
	set_long(
		"һ�Ѻ������۵�С����\n"
	);
	set( "unit", "��" );
        set( "weight", 20 );
	set( "weapon_class", 5 );
	set( "type", "dagger" );
	set( "min_damage", 2 );
	set( "max_damage", 5 );
	set( "second", 1 );
	set( "value", ({ 10, "silver" }) );
}
}
