#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Fire Shield","���ȶ�" );
	add( "id", ({ "shield" }) );
	set_short( "���ȶ�" );
	set_long(@LONG
	�ܹ���ջ���Ķܡ�
LONG
		);
	set( "unit","��" );
	set( "weight",120 );
	set( "type","shield" );
	set( "material","light_metal" );
	set( "armor_class",8 );
	set( "defense_bonus",3 );
	set( "special_defense",([ "fire":30,"cold":-15 ]) );
	set( "value",({ 2150,"silver" }) );
}
