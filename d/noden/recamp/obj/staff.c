#include <mudlib.h>

inherit WEAPON;

void create()
{
	seteuid(getuid());
        set_name( "staff", "����" );
	add( "id", ({ "staff" }) );
   set_short( "����" );
	set_long(
		"���ľ�����涤���˼������̣���Щ���ϻ����е�����\n"
	);
	set( "unit", "��" );
	set( "type", "blunt" );
	set( "weapon_class", 9 );
	set( "min_damage", 3 );
	set( "max_damage", 10 );
	set( "weight", 70 );
	set( "value", ({ 40, "silver" }) );
}
