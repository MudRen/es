#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "snake platemail", "����" );
	add( "id", ({ "plate", "platemail" }) );
	set_short( "�߿���" );
	set_long( @C_LONG
֮���Ա���Ϊ�߼�, ����Ϊ������������ǧֻī��ɫ��С���Ƴ�.
��Щ�߲�֪��������������, ���������̹�, �۾���������ĺ�
��, �������������ǻ��.
C_LONG
	);
	set( "unit", "��" );
	set( "type", "body" );
	set( "material", "heavy_metal");
	set( "armor_class", 30 );
	set( "defense_bonus", 3);
	set( "special_defense",
	     ([ "fire":3, "acid":5, "poison":5, "electric":-6 ]) );
	set( "weight", 400 );
	set( "no_sale", 1);
	set( "value", ({ 8100, "silver" }) );
}
