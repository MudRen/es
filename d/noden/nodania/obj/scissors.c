#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "pruning scissors", "����" );
	add( "id", ({ "scissors", "scissor" }) );
	set_short( "����" );
	set_long(
		"����һ�������޼�ֲ��Ĵ������\n"
	);
	set( "type", "shortblade" );
	set( "weapon_class", 8 );
	set( "min_damage", 3 );
	set( "max_damage", 10 );
	set( "weight", 80 );
	set( "nosecond", 1 );
	set( "value", ({ 65, "silver" }) );
	set_c_verbs( ({ "��%s��%sһ��" }) );
}
