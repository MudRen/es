#include <mudlib.h>

inherit WEAPON;

void create()
{
	seteuid(getuid());
	set_name("waraxe", "ս��");
	add( "id", ({ "axe" }) );
        set_short( "ս��" );
	set_long(
		"���ֳ��ص�ս����רΪǿ׳��սʿ��Ƶġ�\n"
	);
	set( "unit", "��" );
	set( "weight", 110 );
	set( "no_second", 1 );
	setup_weapon( "axe", 17, 10, 20 );
	set( "bleeding", 10 );
	set( "value", ({ 680, "silver" }) );
}
