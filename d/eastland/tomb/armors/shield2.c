#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "holy shield", "��ħ��" );
	add( "id", ({ "shield" }) );
	set_short( "��ħ��" );
	set_long( @C_LONG
һ���������Ķܣ��ݷ����С̫���Ƶġ�
C_LONG
	);
	set( "unit", "��" );
	set( "type", "shield" );
	set( "material", "light_metal");
	set( "armor_class", 6 );
	set( "defense_bonus", 2);
	set( "special_defense",
	     ([ "evil":5,"cold":5 ]) );
	set( "weight", 100 );
	set( "value", ({ 1870, "silver" }) );
}
