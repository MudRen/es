#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "white cape", "������" );
	add( "id", ({ "cape" }) );
	set_short(  "��ɫ����" );
	set_long(
		"�����ɫ���翴������Ư�����Ұ���������һ��СС��õ���־��\n"
	);
	set( "unit", "��" );
	set( "weight", 50 );
	set( "type", "cloak" );
	set( "material" ,"cloth" );
	set( "armor_class", 4 );
	set( "defense_bonus", 3 );
	set( "special_defense", ([ "mental":3 ]) );
	set( "value", ({ 136, "gold" }) );
}
