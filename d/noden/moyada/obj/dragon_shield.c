#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "dragon shield", "���۶�" );
	add( "id", ({ "shield" }) );
	set_short(  "���۶�" );
	set_long( @C_LONG
�����ܾ���һ����ͷ, ��������, ��������. ����ҫ�۵Ľ��, ��ֵһ������.
C_LONG
	);
	set( "unit", "��" );
	set( "type", "shield" );
	set( "material", "heavy_metal");
	set( "armor_class", 9 );
	set( "defense_bonus", 2);
	set( "special_defense",
	     ([ "none":5, "mental":-5 ]) );
	set( "extra_skills",([ "block":7 ]) );     
	set( "weight", 150 );
	set( "no_sale", 1);
	set( "value", ({ 5970, "silver" }) );
}
