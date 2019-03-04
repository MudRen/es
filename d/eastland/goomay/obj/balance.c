#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "balance beam", "��˳�" );
	add( "id", ({ "beam" }) );
	set_short( "a balance beam", "��˳�" );
	set_long(
		"You see a balance beam for trading.\n",
		"����һ�Ѵ�ŵĸ˳ӣ�ר���������ش�ŵĻ����õġ�\n"
	);
	set( "unit", "��" );
	set( "weight", 200 );
	setup_weapon( "polearm", 25, 15, 30 );
	set( "value", ({ 420, "silver" }) );
}
