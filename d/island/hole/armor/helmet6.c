#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Dragon Turban","������ͷ��" );
	add( "id", ({ "turban" }) );
	set_short( "������ͷ��" );
	set_long(@LONG
	���������Ƴɵ�ͷ���ܿ������������ٻ���˺���
LONG
		);
	set( "unit","��" );
	set( "weight",15 );
	set( "type","head" );
	set( "material","leather" );
	set( "armor_class",8 );
	set( "defense_bonus",4 );
	set( "special_defense",([ "fire":15 ]) );
	set( "value",({ 3570,"silver" }) );
}
