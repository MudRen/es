#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "padded robe", "��׻���" );
	add( "id", ({ "robe" }) );
	set_short( "a padded robe", "��׻���" );
	set_long(
		"You see a long robe with padded metal pieces. It looks light and\n"
		"protective.\n",
		"����һ�����ͻ��ۣ������ý���Ƭ���ڼ粿��ǰ�����ᱳ���������൱���\n"
		"���Ҿ߲���ı���Ч����\n"
	);
	set( "unit", "��" );
	set( "type", "body" );
	set( "material", "leather" );
	set( "armor_class", 15 );
	set( "defense_bonus", 5 );
	set( "special_defense", ([ "cold":4, "electric":-5 ]) );
	set( "weight", 80 );
	set( "value", ({ 1300, "silver" }) );
}
