#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "kabuto", "ͷ��" );
   set_short( "��ʽͷ��" );
	set_long(
		"����һ����ʽ��ͷ����������һ�Ի�ͭ���ɵ�¹���Ρ�\n"
	);
	set( "unit", "��" );
	set( "weight", 80 );
	set( "type", "head" );
	set( "material", "light_metal");
	set( "armor_class", 5 );
	set( "defense_bonus", 3 );
	set( "special_defense",
	       ([ "mental":3, "electric":-3, "acid":1 ]) );
	          
	set( "value", ({ 575, "silver" }) );
	set( "no_sale", 1 );
}
