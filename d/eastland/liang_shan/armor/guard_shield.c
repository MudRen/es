#include <../takeda.h>

inherit ARMOR;

void create()
{
	set_name( "Icy shield", "��ˮ����" );
	add( "id", ({ "shield" }) );
	set_short( "Icy shield", "��ˮ����" );
	set_long(
		"??\n",
		"��������ɺ����֮ǧ�������Ƴɣ���δ�����͸е����䣮\n"
	);
	set( "unit", "��" );
	set( "type", "shield" );
	set( "material", "elemental" );
	set( "armor_class", 6 );
	set( "defense_bonus", 5 );
	set( "special_defense", ([ "fire":12 ]) );
	set( "weight", 240 );
	set( "value", ({ 2400, "silver" }) );
}
