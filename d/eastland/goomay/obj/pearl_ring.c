#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "pearl ring", "�����ָ" );
	add( "id", ({ "ring" }) );
	set_short( "a pearl ring", "�����ָ" );
	set_long(
		"You see a beautiful pearl ring with a big pearl on it.\n",
		"����һ����Ư���������ָ����������һ�Ŵ������顣\n"
	);
	set( "type", "finger" );
        set("material","stone");
	set( "defense_bonus", 5 );
	set( "weight", 10 );
	set( "value", ({ 400, "silver" }) );
	
}
