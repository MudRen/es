#include <mudlib.h>

inherit HERB;

void create()
{
	herb::create();
	set_name( "black plaster", "���������" );
	set_short( "���������" );
	add("id",({"plaster"}));
	set_long(
		"�������ϵ�����������ʥƷ,����ҩ����Ѱ�����Է�(apply)���˿��ϡ�\n"
	);
	set( "unit", "��" );
	set( "heal_apply", 9 );
	set( "duration", 30 );
	set( "weight", 10 );
	set( "value", ({ 50, "gold" }) );
}
