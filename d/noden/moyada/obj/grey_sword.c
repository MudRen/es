#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "sword of Grey", "����֮��" );
	add( "id", ({ "sword", "longblade", "blade", }) );
	set_short( "����֮��" );
	set_long( @C_LONG
ð�ռҸ�������õ�����, �����Ͽ���һ��СС������, Ī�����ߵ��Ķ���?
C_LONG
	);
	set( "unit", "��" );
	set( "weapon_class", 34 );
	set( "type", "longblade" );
	set( "min_damage", 18 );
	set( "max_damage", 30 );
	set( "no_sale", 1);
	set( "weight", 100 );
	set( "value", ({ 10930, "silver" }) );
}
