#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "iron chain", "����" );
	add( "id", ({ "chain","whip" }) );
	set_short( "a iron chain", "����" );
	set_long(
		"You see an iron chain which used to lock felonries.\n",
		"����һ���������������ǹ���������׷�÷��˵�������\n"
	);
	set( "unit", "��" );
	set( "weight", 70 );
	setup_weapon( "whip", 15, 8, 16 );
	set( "value", ({ 220, "silver" }) );
        set_c_verbs(({"%s˦��%s","%s����%s","%s����%s"}));
}
