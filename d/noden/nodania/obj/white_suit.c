#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "white suit", "��ɫʫ�˷�" );
	add( "id", ({ "suit" }) );
	set_short( "��ɫʫ�˷�" );
	set_long(
		"����·������ϵȵĲ����Ƴɵģ���������Ư��Ҳ�ܰ���\n"
	);
	set( "unit", "��" );
	set( "type", "body" );
	set( "material", "cloth");
	set( "armor_class", 10 );
	set( "defense_bonus", 2);
	set( "special_defense", ([ "magic":2, "fire":-3 ]) );
	set( "weight", 60 );
	set( "value", ({ 76, "gold" }) );
}
