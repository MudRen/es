#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "crimson ring", "�ʺ�ɫ��ָ" );
	add( "id", ({ "ring" }) );
	set_short( "�ʺ�ɫ��ָ" );
	set_long(
		"����һ���ʺ�ɫ������ָ����������һ�ź챦ʯ��\n"
	);
	set( "type", "finger" );
	set( "material", "element");
	set( "armor_class", 0 );
	set( "defense_bonus", 7 );
	set( "special_defense",
		([ "evil":5, "electric":5,"divine":-7,"none": -5 ]) );
	set( "weight", 10 );
	set( "value", ({ 920, "silver" }) );
	set( "no_sale", 1 );
}
