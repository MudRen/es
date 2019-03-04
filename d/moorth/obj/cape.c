#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black cape", "��ɫ����" );
	add( "id", ({ "cape" }) );
	set_short( "a black cape", "��ɫ����" );
	set_long(
		"You see a black cape with the symbol of Moorth Army on it.\n"
		"����һ����ɫ�����磬������һ��Ĭ��˹���ӵı�־��\n"
	);
	set( "unit", "��" );
	set( "type", "cloak" );
	set( "material", "cloth" );
	set( "armor_class", 4 );
	set( "defense_bonus", 6);
	set( "weight", 70 );
	set( "special_defense", ([ "evil":5,"divine":-7 ]) );
	set( "value", ({ 1000, "silver" }) );
	set( "no_sale", 1 );
}
